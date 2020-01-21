/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:14 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:45:47 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_floor_color(t_parameters *params, const char *line)
{
	t_dint4	color;
	int		i;

	if (params->floor_color != -1)
		quit_program(params, "Floor color has already been set.");
	color.d[2] = ft_atoi(line);
	i = 0;
	while (ft_index(" 0123456789", line[i]) != -1)
		i++;
	i = line[i] == ',' ? i + 1 : i;
	color.d[1] = ft_atoi(&line[i]);
	while (ft_index(" 0123456789", line[i]) != -1)
		i++;
	i = line[i] == ',' ? i + 1 : i;
	color.d[0] = ft_atoi(&line[i]);
	color.d[3] = 0;
	params->floor_color = color.i;
}
