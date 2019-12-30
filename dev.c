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
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
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


void	mlx_img_draw_vertical_line(void **img, int x, t_vec line, t_rgba color)
{
	int i;
	int pp;
	unsigned char *c;

	i = line.x;
	c = *img;
	while (i <= line.y)
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
	int x = 0;

	int buffer[600][800];

	// START RAYCASTING LOOP
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
		dda.linevec.x = dda.linevec.x < 0 ? 0 : dda.linevec.x;
		dda.linevec.y = dda.lineheight / 2 + params->win_height / 2;		
		dda.linevec.y = dda.linevec.y >= params->win_height ? params->win_height - 1 : dda.linevec.y;

		
		// TEXTURE
		int a;
		int b;
		int texx;
		int texy;
		int colort;

		if (dda.side == 0)
			dda.wallx = params->posy + dda.perpwalldist * dda.raydiry;
		else
			dda.wallx = params->posx + dda.perpwalldist * dda.raydirx;
		dda.wallx -= floor(dda.wallx);
		
		texx = (int)(dda.wallx * 64.0);
		if (dda.side == 0 && dda.raydirx > 0)
			texx = 64 - texx - 1;
		if (dda.side == 1 && dda.raydiry < 0)
			texx = 64 - texx - 1;
		
		double step = 1.0 * 64 / dda.lineheight;
		double texpos = (dda.linevec.x - params->win_height / 2 + dda.lineheight / 2) * step;
		b = dda.linevec.x;
		while (b < dda.linevec.y)
		{
			texy = (int)texpos & (64 - 1);
			texpos += step;
			colort = params->texture[64 * texy + texx];
			if (dda.side == 1)
				colort = (colort >> 1) & 8355711;	
			buffer[b][x] = colort;
			b++;
		}	
		
		// buffer_to_img();
		// x * 4 + 4 + 3200 * y;
		unsigned char *c = params->img;
		int pp;
		a = 0;
		b = 0;
	
		while (a < 600)
		{
			while (b < 800)
			{
				pp = b * 4 + 4 + 3200 * a;
				c[pp] = buffer[a][b] / 65536;	
				c[pp + 1] = (buffer[a][b] / 256) % 256;	
				c[pp + 2] = buffer[a][b] % 256;
				b++;
			}
			a++;
			b = 0;
		}
		
		/* clear buffer
		a = 0;
		b = 0;
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
		*/
		/*
		color.r = 200;
		color.g = 200;
		color.b = 200;
		color.a = 0;
		if (dda.side == 1) { color.r -= 50; }	
		if (dda.side == 1) { color.g -= 50; }	
		if (dda.side == 1) { color.b -= 50; }	

		mlx_img_draw_vertical_line(&(params->img), x, dda.linevec, color);
		t_vec cf;
		// start end ceiling
		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 0;
		if (dda.linevec.x > 0)
		{
			cf.x = 0;
			cf.y = dda.linevec.x - 1;
			mlx_img_draw_vertical_line(&(params->img), x, cf, color);
		}

		// start end floor
		color.r = 100;
		color.g = 100;
		color.b = 100;
		color.a = 0;
		if (dda.linevec.y < params->win_height - 1)
		{
			cf.x = dda.linevec.y + 1;
			cf.y = params->win_height - 1;
			mlx_img_draw_vertical_line(&(params->img), x, cf, color);
		}
		*/
		x++;
	}
	
	mlx_put_image_to_window(params->mlx_id, params->win_id, params->img_id, 0, 0);
	mlx_clear_img(&(params->img));
}
