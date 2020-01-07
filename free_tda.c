/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:37:33 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/07 16:06:42 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    free_tda(void **two_dimensional_array, int first_dimension_length)
{
	int i;

	i = 0;
	while (i < first_dimension_length)
	{
		free(two_dimensional_array[i]);
		i++;
	}
	two_dimensional_array = NULL;
}
