#include "header.h"

void	set_params_to_default(t_parameters *params)
{
	params->win_h = 0;
	params->win_w = 0;
	params->map_h = 0;
	params->map_w = 0;
	params->map = NULL;
	params->posx = 0;
	params->posy = 0;
	params->dirx = 2;
	params->diry = 2;
	params->planex = 2;
	params->planey = 2;
	params->no_tex = NULL;
	params->so_tex = NULL;
	params->we_tex = NULL;
	params->ea_tex = NULL;
	params->s_tex = NULL;
	params->floor_color = -1;
	params->ceiling_color = -1;
}
