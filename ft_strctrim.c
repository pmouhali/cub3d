/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:12:27 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/07 12:57:31 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strctrim(const char *s, int c)
{
	int i;
	int j;
	char *new;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c)
			j++;
	if (!(new = (char*)malloc(sizeof(char) * (j + 1))))
		return (new);
	new[j] = 0;
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != c)
			new[++j] = s[i];	
	}
	return (new);
}
