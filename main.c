/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:05:45 by jfox              #+#    #+#             */
/*   Updated: 2025/12/29 13:42:28 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*lines;
	int		fd1;
	int		fd2;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	do
	{
		lines = get_next_line(fd1);
		printf("%s", lines);
		free(lines);
		lines = get_next_line(fd2);
		printf("%s", lines);
		free(lines);
	}	while (lines);
	free(lines);
	return (0);
}
