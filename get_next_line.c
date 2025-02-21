/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:43 by maborges          #+#    #+#             */
/*   Updated: 2025/02/21 11:09:28 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read_file(int fd)
{
	char		*tmpbuff;
	int			alreadyread;
	static int	count;


	alreadyread = 1;
	printf("ft_calloc #%d --", count++);
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
		return (free(tmpbuff), NULL);
	alreadyread = read(fd, (char *)tmpbuff, BUFFER_SIZE);
	if (alreadyread <= 0)
		return (free(tmpbuff), NULL);
	return (tmpbuff);
}

char	*get_next_line(int fd)
{
	char	*big_buff;

	big_buff = ft_read_file(fd);
	return (big_buff);
}
