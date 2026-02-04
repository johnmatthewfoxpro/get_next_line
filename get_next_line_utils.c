/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:49:36 by jfox              #+#    #+#             */
/*   Updated: 2025/12/29 13:34:38 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strichr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = ft_strlen(src);
	if (size == 0)
	{
		return (x);
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (x);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	lenx;

	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	lenx = (len1 + ft_strlen(s2));
	s3 = (char *)ft_calloc((lenx + 1), sizeof(char));
	if (!s3)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(s3, s1, (len1 + 1));
		free(s1);
	}
	ft_strlcpy(&s3[len1], s2, ft_strlen(s2) + 1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	char	*result;

	if (!s)
		return (NULL);
	i = start;
	x = 0;
	if (start >= ft_strlen(s))
	{
		result = (char *)ft_calloc(1, sizeof(char));
		return (result);
	}
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	result = (char *)ft_calloc((len) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s[x] && x < len)
	{
		result[x] = s[i + x];
		x++;
	}
	return (result);
}
