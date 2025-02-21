/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:44 by maborges          #+#    #+#             */
/*   Updated: 2025/02/21 11:09:29 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int	main(void)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 0;
	fd = open("multiline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("This looks like an error!");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		line_number++;
		printf("%d :: %s\n", line_number, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
