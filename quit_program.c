/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:30:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/03 16:32:39 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	quit_program(t_parameters *params, const char *error_msg)
{
//	free_int_tab(params->map, params->map_width);
//	print_int_tab(params->map, params->map_width);
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	exit(1);
}
