/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ceiling_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:08 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 13:17:41 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_ceiling_color(t_parameters *params, const char *line)
{
	t_dint4	color;
	int		i;
	char	*trim;

	if (params->ceiling_color != -1)
		quit_program(params, "Ceiling color has already been set.");
	trim = ft_strctrim(line, 32);
	if (trim[0] < 48 || trim[0] > 57)
		quit_program(params, "ceiling color: incorrect rgb.");
	color.d[2] = ft_atoi(trim);
	i = 0;
	while (ft_index("0123456789", trim[i]) != -1)
		i++;
	i = trim[i] == ',' ? i + 1 : i;
	if (trim[i] < 48 || trim[i] > 57)
		quit_program(params, "ceiling color: incorrect.");
	color.d[1] = ft_atoi(&trim[i]);
	while (ft_index("0123456789", trim[i]) != -1)
		i++;
	i = trim[i] == ',' ? i + 1 : i;
	if ((trim[i] < 48 || trim[i] > 57) || (color.d[3] = 0))
		quit_program(params, "ceiling color: incorrect.");
	color.d[0] = ft_atoi(&trim[i]);
	free(trim);
	params->ceiling_color = color.i;
}
