/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:41 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/15 15:18:38 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if ((!dest && !src) || dest == src)
		return (dest);
	cdest = dest;
	csrc = src;
	i = 0;
	if (dest <= src)
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	else
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	return (dest);
}

char			*ft_strnjoin(char *s1, char const *s2, long n)
{
	long			j;
	char			*new;
	unsigned long	i;

	i = s1 == ((void*)0) ? 0 : ft_strlen(s1);
	j = ft_strlen(s2);
	if (n == -1 || n > j)
		n = j;
	if (!(new = (char*)malloc(sizeof(char) * (i + n + 1))))
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i] != '\0')
			new[i] = s1[i];
		free(s1);
	}
	j = -1;
	while (j < n && s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}
