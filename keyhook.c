#include "header.h"

int	key_hook(int keycode,void *params)
{
	t_parameters *copy;
	double olddirx;
	double oldplanex;
	double rotspeed;

	copy = params;
	if (keycode == 126)
	{
		if (copy->map[(int)(copy->posx + copy->dirx * MOVESPEED)][(int)copy->posy] == 0)
			copy->posx += copy->dirx * MOVESPEED;
		if (copy->map[(int)copy->posx][(int)(copy->posy + copy->diry * MOVESPEED)] == 0)
			copy->posy += copy->diry * MOVESPEED;
	}
	if (keycode == 125)
	{
		if (copy->map[(int)(copy->posx - copy->dirx * MOVESPEED)][(int)copy->posy] == 0)
			copy->posx -= copy->dirx * MOVESPEED;
		if (copy->map[(int)copy->posx][(int)(copy->posy - copy->diry * MOVESPEED)] == 0)
			copy->posy -= copy->diry * MOVESPEED;
	}
	if (keycode == 124 || keycode == 123) // RIGHT = 124 LEFT = 123
	{
		rotspeed = keycode == 124 ? -ROTSPEED : ROTSPEED;
		olddirx = copy->dirx;
		copy->dirx = copy->dirx * cos(rotspeed) - copy->diry * sin(rotspeed);
		copy->diry = olddirx * sin(rotspeed) + copy->diry * cos(rotspeed);
		oldplanex = copy->planex;
		copy->planex = copy->planex * cos(rotspeed) - copy->planey * sin(rotspeed);
		copy->planey = oldplanex * sin(rotspeed) + copy->planey * cos(rotspeed);
	}
	if (keycode == 53)
		quit_program(params);

	draw_scene(copy);

	return (0);
}
