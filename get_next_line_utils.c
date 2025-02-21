/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:09 by maborges          #+#    #+#             */
/*   Updated: 2025/02/21 15:28:19 by maborges         ###   ########.fr       */
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
