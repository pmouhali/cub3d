/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:30:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/14 18:28:46 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_texture(t_texture *t)
{
	if (t->id)
		free(t->id);
	if (t->img)
		free(t->img);
}

void	quit_program(t_parameters *params, const char *error_msg)
{
	if (params->win_id)
		mlx_destroy_window(params->mlx_id, params->win_id);
	if (params->mlx_id)
		free(params->mlx_id);
	if (params->img_id)
		free(params->img_id);
	if (params->img)
		free(params->img);
	free_texture(&(params->north_texture));
	free_texture(&(params->south_texture));
	free_texture(&(params->east_texture));
	free_texture(&(params->west_texture));
	free_texture(&(params->sprite_texture));
	if (params->map)
		free_tda((void**)params->map, params->map_h);
	if (error_msg)
		ft_puterror(error_msg);
	exit(1);
}
