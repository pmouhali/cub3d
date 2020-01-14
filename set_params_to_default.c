#include "header.h"

void	set_params_to_default(t_parameters *params)
{
	params->win_id = NULL;
	params->img_id = NULL;
	params->img = NULL;
	params->win_h = 0;
	params->win_w = 0;
	params->map_h = 0; // surely uneeded
	params->map_w = 0; // same
	params->map = NULL;
	params->posx = 0;
	params->posy = 0;
	params->dirx = 0;
	params->diry = 0;
	params->planex = 0;
	params->planey = 0;
	params->north_texture.id = NULL;
	params->north_texture.img = NULL;
	params->south_texture.id = NULL;
	params->south_texture.img = NULL;
	params->east_texture.id = NULL;
	params->east_texture.img = NULL;
	params->west_texture.id = NULL;
	params->west_texture.img = NULL;
	params->sprite_texture.id = NULL;
	params->sprite_texture.img = NULL;
	params->floor_color = -1;
	params->ceiling_color = -1;
}
