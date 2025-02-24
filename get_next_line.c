/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:43 by maborges          #+#    #+#             */
/*   Updated: 2025/02/24 14:24:24 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*join_buffers(char *stash, char *tmp)
{
	stash = ft_strjoin(*stash, tmp);
	return (&stash);
}

static char	*leftover(char *stash)
{
	char	*extracted_line;
	char	*remaining_line;

	extracted_line = ft_strchr(*stash, '\n');
	remaining_line = *stash - *extracted_line;
	return (remaining_line);
}

static char	*extract_line(char *stash)
{
	char	*extracted_line;

	extracted_line = ft_strchr(*stash, '\n');
	return (extracted_line);
}

static char	*ft_read_file(char *stash, int fd)
{
	char		*tmpbuff;
	int			bytes_read;
	static int	count;

	bytes_read = 1;
	printf("ft_calloc #%d --", count++);
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
		return (free(tmpbuff), NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, (char *)tmpbuff, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(tmpbuff), NULL);
		tmpbuff[bytes_read] = '\0';
		stash = join_buffers(stash, tmpbuff);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(tmpbuff);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!ft_strchr(stash, '\n'))
		stash = ft_read_file(stash, fd);
	if (!stash)
		return (free(stash), NULL);
	line = extract_line(&stash);
	stash = leftover(stash);
	return (line);
}

/* //need to find the first new line char in the stash
//use strchr to find the newline char
//take out the line you want with substr
// line = newline position - stash + 1 for the '\n'
//make a temp variable that has the rest of the content that you want
//free the stash of old material
//update the stash with the remaining from temp variable */
