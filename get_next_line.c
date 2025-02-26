/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:43 by maborges          #+#    #+#             */
/*   Updated: 2025/02/26 14:12:10 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*join_buffers(char *stash, char *tmpbuff)
{
	char	*tmp;

	tmp = ft_strjoin(stash, tmpbuff);
	free(stash);
	return (tmp);
}

static char	*leftover(char *stash)
{
	char	*remaining_line;
	char	*newstash;

	remaining_line = ft_strchr(stash, '\n');
	if (remaining_line)
	{
		remaining_line += 1;
		newstash = ft_strdup(remaining_line);
		free(stash);
		if (!newstash)
			return (NULL);
		return (newstash);
	}
	free(stash);
	return (NULL);
}

static char	*extract_line(char *stash)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' || stash[i] != '\0')
		i++;
	extracted_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] != '\n' || stash[i] != '\0')
	{
		extracted_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' || stash[i] == '\0')
	{
		extracted_line[i] = '\n';
		extracted_line[i++] = '\0';
	}
	return (extracted_line);
}

static char	*ft_read_file(char *stash, int fd)
{
	char		*tmpbuff;
	int			bytes_read;

	bytes_read = 1;
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmpbuff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (tmpbuff);
			free (stash);
			return (NULL);
		}
		tmpbuff[bytes_read] = '\0';
		stash = join_buffers(stash, tmpbuff);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(tmpbuff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	if (stash && !ft_strchr(stash, '\n'))
		stash = ft_read_file(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
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
