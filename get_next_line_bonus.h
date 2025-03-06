/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:29 by maborges          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/05 13:05:11 by maborges         ###   ########.fr       */
=======
/*   Updated: 2025/03/05 18:01:09 by maborges         ###   ########.fr       */
>>>>>>> cb1e2ad (Null'd stash, passing mull check)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> /* for read() and close()*/
# include <fcntl.h> /* for read() flags*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h> /* free and malloc */

char		*get_next_line(int fd);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char **stash, char const *s2);
char		*ft_strdup(const char *s);

#endif
