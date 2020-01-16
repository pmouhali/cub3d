#include "header.h"

void	initialize_cub3d(t_parameters *params, const char *arg1)
{
	set_params_to_default(params);
	params->mlx_id = mlx_init();
	if (!params->mlx_id)
		quit_program(params, "Minilibx initilization failed.");
	init_params(params, arg1);
}
