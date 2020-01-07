/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/07 13:10:04 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	validate_file(t_parameters *params, const char *filepath)
{
	if (ft_strcmp(ft_strrchr(filepath, '.'), ".cub"))
		quit_program(params, "Error: not a .cub file.");
	params->fd = open(filepath, O_RDONLY);
	if (params->fd < 3)
		quit_program(params, "Error: can't open file.");
	params->config_file = (char*)filepath;
}
