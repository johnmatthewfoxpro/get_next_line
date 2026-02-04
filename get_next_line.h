/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:51:05 by jfox              #+#    #+#             */
/*   Updated: 2025/12/24 15:09:11 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/***********************\
*    GET NEXT LINE      *
\***********************/
char	*get_next_line(int fd);

/***********************\
*   HELPER FUNCTIONS    *
\***********************/
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strichr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
