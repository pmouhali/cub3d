#include "header.h"
#include <stdio.h>
 
int     map[10][10] = {
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
                  {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	mlx_img_draw_vertical_line(void **img, int x, t_vec line, t_rgba color)
{
	int i;
	int pp;
	unsigned char *c;

	i = line.x;
	c = *img;
	while (i != line.y)
	{
		pp = x * 4 + 4 + 3200 * i;
		c[pp] = color.r;	
		c[pp + 1] = color.g;	
		c[pp + 2] = color.b;	
		i++;
	}
}

void	mlx_clear_img(void **img)
{
	int i = 0;
	unsigned char *c;

	t_rgba color;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.a = 0;

	t_vec vec;
	vec.x = 0;
	vec.y = 599;

	c = *img;
	while (i < 800)
	{
		mlx_img_draw_vertical_line(img, i, vec, color);
		i++;
	}
}

int	key_hook(int keycode,void *params)
{
	t_parameters *copy;

	copy = params;
	if (keycode == 126)
	{
		copy->posx += copy->dirx;
		copy->posy += copy->diry;
	}
	if (keycode == 125)
	{
		copy->posx -= copy->dirx;
		copy->posy -= copy->diry;
	}
	if (keycode == 124)
	{
		copy->olddirx = copy->dirx;
		copy->dirx = copy->dirx * cos(-0.1) - copy->diry * sin(-0.1);
		copy->diry = copy->olddirx * sin(-0.1) + copy->diry * (-0.1);
		copy->oldplanex = copy->planex;
		copy->planex = copy->planex * cos(-0.1) - copy->planey * sin(-0.1);
		copy->planey = copy->oldplanex * sin(-0.1) + copy->planey * cos(-0.1);
	}
	if (keycode == 53)
		exit(1);

	draw_scene(copy);

	return (0);
}

void	draw_scene(t_parameters *tmp)
{
	t_rgba color;
	t_dda_parameters dda;
	t_parameters *params = tmp;
	int x = 0;

	while (x < params->win_width)
	{
		dda.camerax = 2 * x / (double)params->win_width - 1;	
		dda.raydirx = params->dirx + params->planex * dda.camerax;
		dda.raydiry = params->diry + params->planey * dda.camerax;
		dda.mapx = (int)params->posx;
		dda.mapy = (int)params->posy;
		dda.hit = 0;
	
		dda.deltadistx = fabs(1 / dda.raydirx);
		dda.deltadisty = fabs(1 / dda.raydiry);

		if (dda.raydirx < 0)
		{
			dda.stepx = -1;
			dda.sidedistx = (params->posx - dda.mapx) * dda.deltadistx;
		}
		else
		{
			dda.stepx = 1;
			dda.sidedistx = (dda.mapx + 1.0 - params->posx) * dda.deltadistx;
		}
		if (dda.raydiry < 0)
		{
			dda.stepy = -1;
			dda.sidedisty = (params->posy - dda.mapy) * dda.deltadisty;
		}
		else
		{
			dda.stepy = 1;
			dda.sidedisty = (dda.mapy + 1.0 - params->posy) * dda.deltadisty;
		}
		
		while (dda.hit == 0)
		{
			if (dda.sidedistx < dda.sidedisty)
			{
				dda.sidedistx += dda.deltadistx;
				dda.mapx += dda.stepx;
				dda.side = 0;
			}
			else
			{
				dda.sidedisty += dda.deltadisty;
				dda.mapy += dda.stepy;
				dda.side = 1;
			}
			if (map[dda.mapx][dda.mapy] > 0)
				dda.hit = 1;
		}

		if (dda.side == 0)
			dda.perpwalldist = (dda.mapx - params->posx + (1 - dda.stepx) / 2) / dda.raydirx;	
		else
			dda.perpwalldist = (dda.mapy - params->posy + (1 - dda.stepy) / 2) / dda.raydiry;	

		dda.lineheight = (int)(params->win_height / dda.perpwalldist);

		dda.linevec.x = -dda.lineheight / 2 + params->win_height / 2;		
		//dda.linevec.x = dda.linevec.x < 0 ? 0 : dda.linevec.x;
		dda.linevec.y = dda.lineheight / 2 + params->win_height / 2;		
		//dda.linevec.y = dda.linevec.y >= params->win_height ? 0 : params->win_height - 1;

		color.r = 0;
		color.g = 255;
		color.b = 0;
		color.a = 0;
		
		if (dda.side == 1) { color.b = color.b / 2; }	

		mlx_img_draw_vertical_line(&(params->img), x, dda.linevec, color);

		x++;
	}

	mlx_put_image_to_window(params->mlx_id, params->win_id, params->img_id, 0, 0);
	mlx_clear_img(&(params->img));
}
