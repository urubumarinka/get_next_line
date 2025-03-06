/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:32:43 by maborges          #+#    #+#             */
/*   Updated: 2025/03/06 17:01:51 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read_file(char **stash, int fd);
static char	*extract_line(char *stash);
static char	*leftover(char **stash);

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	stash = ft_read_file(&stash, fd);
	//if ft read file u return NULL... one string gets abandoned
	if (!stash || *stash == '\0')
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	//up to here u only work on stash
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	//have to return and free and stuff if failes
	stash = leftover(&stash);
	return (line);
}

static char	*ft_read_file(char **stash, int fd)
{
	char		*tmpbuff;
	int			bytes_read;
	char		*temp;

	bytes_read = 1;
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
{
		free(*stash);
		*stash = NULL;
		return (NULL);
}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmpbuff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free (tmpbuff);
			return (*stash);
		}
		tmpbuff[bytes_read] = '\0';
		temp = *stash;
		*stash = ft_strjoin(*stash, tmpbuff);
		free(temp);
		if (!*stash)
			return (free(tmpbuff), NULL);
		if (ft_strchr(*stash, '\n'))
			break ;
	}
	free(tmpbuff);
	tmpbuff = NULL;
	return (*stash);
}

static char	*extract_line(char *stash)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	extracted_line = ft_calloc(i + 1, sizeof(char));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		extracted_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		extracted_line[i++] = '\n';
	extracted_line[i] = '\0';
	return (extracted_line);
}

static char	*leftover(char **stash)
{
	char	*remaining_line;
	char	*newstash;

	remaining_line = ft_strchr(*stash, '\n');
	if (remaining_line)
	{
		remaining_line += 1;
		newstash = ft_strdup(remaining_line);
		free(*stash);
		*stash = NULL;
		if (!newstash)
			return (NULL);
		return (newstash);
	}
	free(*stash);
	*stash = NULL;
	return (NULL);
}


