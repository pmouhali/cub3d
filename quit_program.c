/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:30:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/07 17:28:17 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	quit_program(t_parameters *params, const char *error_msg)
{	
	if (params->fd > 2)
		close(params->fd);
	if (params->map)
		free_tda((void**)params->map, params->map_h);
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	exit(1);
}
