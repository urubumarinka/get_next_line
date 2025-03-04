/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:44 by maborges          #+#    #+#             */
/*   Updated: 2025/03/04 22:01:30 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("multi_0.txt", O_RDONLY);
	fd2 = open("multiline.txt", O_RDONLY);
	if (1024 < fd1 < 0 || 1024 < fd2 < 0 || BUFFER_SIZE <= 0)
	{
		printf("This looks like an error!");
		return (1);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 || !line2)
		{
			free(line1);
			free(line2);
			break ;
		}
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
		line1 = NULL;
		line2 = NULL;
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		if (!line1)
		{
			free(line1);
			break ;
		}
		printf("%s", line1);
		free(line1);
		line1 = NULL;
	}
	while (1)
	{
		line2 = get_next_line(fd2);
		if (!line2)
		{
			free(line2);
			break ;
		}
		printf("%s", line2);
		free(line2);
		line2 = NULL;
	}
	close(fd1);
	close(fd2);
	return (0);
}
