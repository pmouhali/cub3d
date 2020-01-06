/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:38:19 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/15 12:33:40 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <header.h>

#define BUFFER_SIZE 50

int		get_next_line(int fd, char **line);
char	*ft_strndup(const char *s, long n);
char	*ft_strnjoin(char *s1, char const *s2, long n);
void	*ft_memmove(void *dest, const void *src, unsigned long n);

#endif
