#include "header.h"
#include <stdio.h>
/*
int     map[20][20] = {
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
*/

int     map[20][20] = {
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	mlx_clear_img(void **img)
{
	int i = 0;
	unsigned char *c;

	c = *img;
	while (i++ < 1920000)
		c[i] = 0;
}

#define MOVESPEED 0.16

#define ROTSPEED 0.09

int	key_hook(int keycode,void *params)
{
	t_parameters *copy;
	double olddirx;
	double oldplanex;
	double rotspeed;

	copy = params;
	if (keycode == 126)
	{
		if (map[(int)(copy->posx + copy->dirx * MOVESPEED)][(int)copy->posy] == 0)
			copy->posx += copy->dirx * MOVESPEED;
		if (map[(int)copy->posx][(int)(copy->posy + copy->diry * MOVESPEED)] == 0)
			copy->posy += copy->diry * MOVESPEED;
	}
	if (keycode == 125)
	{
		if (map[(int)(copy->posx - copy->dirx * MOVESPEED)][(int)copy->posy] == 0)
			copy->posx -= copy->dirx * MOVESPEED;
		if (map[(int)copy->posx][(int)(copy->posy - copy->diry * MOVESPEED)] == 0)
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
		exit(1);

	draw_scene(copy);

	return (0);
}

void	draw_scene(t_parameters *tmp)
{
	t_rgba color;
	t_dda_parameters dda;
	t_parameters *params = tmp;
	int x = -1;

	int buffer[600][800];
	int a = 0;
	int b;
	while (a < 600)
	{
		while (b < 800)
		{
			buffer[a][b] = 0;
			b++;
		}
		a++;
		b = 0;
	}

	// START RAYCASTING LOOP
	while (x < params->win_width - 1)
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
				if (dda.raydirx < 0) // NO
					dda.side = 0;
				else // SO
					dda.side = 1;
			}
			else
			{
				dda.sidedisty += dda.deltadisty;
				dda.mapy += dda.stepy;
				if (dda.raydiry < 0)
					dda.side = 2; // WE
				else
					dda.side = 3; // EA
			}
			if (map[dda.mapx][dda.mapy] > 0)
				dda.hit = 1;
		}

		if (dda.side == 0 || dda.side == 1)
			dda.perpwalldist = (dda.mapx - params->posx + (1 - dda.stepx) / 2) / dda.raydirx;	
		else
			dda.perpwalldist = (dda.mapy - params->posy + (1 - dda.stepy) / 2) / dda.raydiry;	

		dda.lineheight = (int)(params->win_height / dda.perpwalldist);

		dda.linevec.x = -dda.lineheight / 2 + params->win_height / 2;		
		dda.linevec.x = dda.linevec.x < 0 ? 0 : dda.linevec.x;
		dda.linevec.y = dda.lineheight / 2 + params->win_height / 2;		
		dda.linevec.y = dda.linevec.y >= params->win_height ? params->win_height - 1 : dda.linevec.y;

		// TEXTURE
		int a;
		int b;
		int texx;
		int texy;
		int colort;

		if (dda.side == 0 || dda.side == 1)
			dda.wallx = params->posy + dda.perpwalldist * dda.raydiry;
		else
			dda.wallx = params->posx + dda.perpwalldist * dda.raydirx;
		dda.wallx -= floor(dda.wallx);
		
		texx = (int)(dda.wallx * 64.0);
		if ((dda.side == 0  || dda.side == 1) && dda.raydirx > 0)
			texx = 64 - texx - 1;
		if ((dda.side == 2 || dda.side == 3) && dda.raydiry < 0)
			texx = 64 - texx - 1;
		
		double step = 1.0 * 64 / dda.lineheight;
		double texpos = (dda.linevec.x - params->win_height / 2 + dda.lineheight / 2) * step;
		int *texture = params->texture;
		b = dda.linevec.x;
		while (b < dda.linevec.y)
		{
			texy = (int)texpos & (64 - 1);
			texpos += step;
			colort = texture[64 * texy + texx];
			if (dda.side == 2 || dda.side == 3)
				colort = (colort >> 1) & 8355711;	
			buffer[b][x] = colort;
			b++;
		}
		if (dda.linevec.x > 0) // CEILING
		{
			b = 0;
			while (b < dda.linevec.x)
			{
				buffer[b][x] = 16777215;
				b++;
			}
		}
		if (dda.linevec.y < params->win_height - 1) // FLOOR
		{
			b = dda.linevec.y;
			while (b < params->win_height - 1)
			{
				buffer[b][x] = 50;
				b++;
			}
		}

		x++;
	}
	
	unsigned char *c = params->img;
	int pp;
	a = 0;

	while (a < 600)
	{
		while (b < 800)
		{
			pp = b * 4 + 4 + 3200 * a;
			c[pp + 2] = buffer[a][b] / 65536;	
			c[pp + 1] = (buffer[a][b] / 256) % 256;	
			c[pp] = buffer[a][b] % 256;
			b++;
		}
		a++;
		b = 0;
	}

	mlx_put_image_to_window(params->mlx_id, params->win_id, params->img_id, 0, 0);
	mlx_clear_img(&(params->img));
}
