/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:49:05 by jfox              #+#    #+#             */
/*   Updated: 2025/12/29 13:32:40 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buf;
	size_t	i;
	char	*ptr;

	i = 0;
	if (size > 0 && nmemb * size / size != nmemb)
		return (NULL);
	buf = nmemb * size;
	ptr = malloc(buf);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

static char	*build_line(int fd, char *stash, int *goodread)
{
	char	*unchecked_line;
	char	*temp;

	unchecked_line = stash;
	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (NULL);
	*goodread = 1;
	while (!ft_strichr(unchecked_line, '\n') && *goodread != 0)
	{
		*goodread = read(fd, temp, BUFFER_SIZE);
		if (*goodread == -1)
		{
			free(unchecked_line);
			free(temp);
			return (NULL);
		}
		temp[*goodread] = '\0';
		unchecked_line = ft_strjoin(unchecked_line, temp);
	}
	free(temp);
	return (unchecked_line);
}

static char	*check_line(char **stash)
{
	char	*checked_line;
	char	*tmp;
	int		len;

	if (*stash == NULL)
		return (NULL);
	len = 0;
	tmp = *stash;
	while (tmp[len] != '\n' && tmp[len])
		len++;
	if (tmp[len] == '\n')
		len++;
	checked_line = ft_substr(*stash, 0, len);
	if (!checked_line)
		return (NULL);
	tmp = ft_substr(*stash, len, ft_strlen(*stash));
	free(*stash);
	*stash = tmp;
	return (checked_line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*newline;
	int			goodread;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = build_line(fd, stash[fd], &goodread);
	newline = check_line(&stash[fd]);
	if ((newline == NULL || *newline == '\0'))
	{
		free(newline);
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (newline);
}
