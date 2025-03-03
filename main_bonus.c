/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:44 by maborges          #+#    #+#             */
/*   Updated: 2025/03/03 17:17:37 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 0;
	fd = open("multiple_nl.txt", O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("This looks like an error!");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
			return (0);
		line_number++;
		printf("%d :: %s", line_number, line);
		free(line);
	}
	get_next_line(-1);
	close(fd);
	return (0);
}
