/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:57:04 by maborges          #+#    #+#             */
/*   Updated: 2025/03/06 23:15:03 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*stash[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd < 0)
			return (NULL);
		else
			return (free_and_null(&stash[fd]));
	}
	if (!stash[fd])
		stash[fd] = ft_calloc(1, sizeof(char));
	if (!stash[fd])
		return (NULL);
	stash[fd] = ft_read_file(stash[fd], fd);
	if (!stash[fd] || *stash[fd] == '\0')
		return (free_and_null(&stash[fd]));
	line = extract_line(stash[fd]);
	if (!line)
		return (free_and_null(&stash[fd]));
	stash[fd] = leftover(stash[fd]);
	return (line);
}

char	*ft_read_file(char *stash, int fd)
{
	char		*tmpbuff;
	int			bytes_read;
	char		*temp;

	bytes_read = 1;
	tmpbuff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmpbuff)
		return (free_and_null(&stash));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmpbuff, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free (tmpbuff), stash);
		tmpbuff[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, tmpbuff);
		free(temp);
		if (!stash)
			return (free(tmpbuff), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(tmpbuff);
	return (stash);
}

char	*extract_line(char *stash)
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

char	*leftover(char *stash)
{
	char	*remaining_line;
	char	*newstash;

	remaining_line = ft_strchr(stash, '\n');
	if (remaining_line)
	{
		remaining_line += 1;
		newstash = ft_strdup(remaining_line);
		if (!newstash)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		return (newstash);
	}
	free(stash);
	return (NULL);
}

char	*free_and_null(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}
