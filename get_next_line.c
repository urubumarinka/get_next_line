/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:43 by maborges          #+#    #+#             */
/*   Updated: 2025/02/21 18:19:41 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read_file(char *stash, int fd)
{
	char		*tmpbuff;
	int			bytes_read;
	static int	count;

	bytes_read = 1;
	count = 1;
	printf("ft_calloc #%d --", count++);
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
		return (free(tmpbuff), NULL);
	bytes_read = read(fd, (char *)tmpbuff, BUFFER_SIZE);
	tmpbuff[bytes_read] = '\0';
	ft_strjoin(stash, tmpbuff);
	if (bytes_read <= 0)
		return (free(tmpbuff), NULL);
	free(tmpbuff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char 			*line;

	stash = ft_read_file(stash, fd);
	/* while (!ft_strchr(stash, '\n'))
	{
	} */
	//need to find the first new line char in the stash
	//use strchr to find the newline char
	//take out the line you want with substr
	// line = newline position - stash + 1 for the '\n'
	//make a temp variable that has the rest of the content that you want
	//free the stash of old material
	//update the stash with the remaining from temp variable
	line = stash;
	return (line);
}
