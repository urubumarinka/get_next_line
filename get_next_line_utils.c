/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:09 by maborges          #+#    #+#             */
/*   Updated: 2025/02/24 17:21:50 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		str[n - 1] = (unsigned char)c;
		n--;
	}
	return ((void *)s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
		return (0);
	array = malloc(nmemb * size);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	ft_memset(array, 0, nmemb * size);
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
