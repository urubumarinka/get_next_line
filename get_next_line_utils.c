/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:09 by maborges          #+#    #+#             */
/*   Updated: 2025/03/03 13:59:43 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	size_t			i;
	size_t			total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_size = nmemb * size;
	if (nmemb > 0 && size > 0 && (total_size / nmemb) != size)
		return (NULL);
	array = malloc(total_size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)array)[i] = 0;
		i++;
	}
	return (array);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmpstr;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmpstr = malloc((i + j + 1) * sizeof(char));
	if (!tmpstr)
		return (NULL);
	count = 0;
	while (count < i)
	{
		tmpstr[count] = s1[count];
		count++;
	}
	while (count < j + i)
	{
		tmpstr[count] = s2[count - i];
		count++;
	}
	tmpstr[count] = '\0';
	return (tmpstr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tmps1;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	tmps1 = (char *) malloc((i + 1) * sizeof(char));
	if (!tmps1)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tmps1[i] = s[i];
		i++;
	}
	tmps1[i] = '\0';
	return (tmps1);
}
