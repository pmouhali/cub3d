/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:37:33 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/03 15:03:37 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_int_tab(int **tab, int array_size)
{
	int i;
	int j;

	i = -1;
	while (++i < array_size)
	{
		j = 0;
		while (j < array_size)
		{
			printf("%i", tab[i][j]);
			j++;
		}
		printf("\n");
	}
}
