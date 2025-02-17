/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:44 by maborges          #+#    #+#             */
/*   Updated: 2025/02/17 19:22:01 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int	main(void)
{
	int	fd;
	char	*line;


	fd = open("multiline.txt", O_RDONLY);
	line = get_next_line(fd);

	close(fd);
	return(0);
}
