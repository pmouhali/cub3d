#include "header.h"
#include <stdio.h>

void	draw_scene(t_parameters *tmp)
{
	t_dda_parameters dda;
	t_parameters *params = tmp;
	int x = 0;

	int buffer[params->win_height][params->win_width];
	int b = 0;

	// textures
	int texx;
	int texy;
	int color;

	// sprites
	double zbuffer[params->win_width];

	t_sprite sprites[SPRITES_QUANTITY];
	int si = -1;
	sprites[0].x = 0;
	sprites[0].y = 0;
	sprites[0].distance = 0.0;
	sprites[1].x = 0;
	sprites[1].y = 0;
	sprites[1].distance = 0.0;
	
	clear_2dbuffer(600, 800, buffer);
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
			if (params->map[dda.mapx][dda.mapy] == 1)
				dda.hit = 1;
			else if (params->map[dda.mapx][dda.mapy] == 2
				&& si < SPRITES_QUANTITY - 1  &&
					(sprites[si].x != dda.mapx
						|| sprites[si].y != dda.mapy))
			{
				si++;
				sprites[si].x = dda.mapx;
				sprites[si].y = dda.mapy;
			}
		}

		if (dda.side == 0 || dda.side == 1)
			dda.perpwalldist = (dda.mapx - params->posx + (1 - dda.stepx) / 2) / dda.raydirx;	
		else
			dda.perpwalldist = (dda.mapy - params->posy + (1 - dda.stepy) / 2) / dda.raydiry;	

		zbuffer[x] = dda.perpwalldist; 

		dda.lineheight = (int)(params->win_height / dda.perpwalldist);

		dda.linevec.x = -dda.lineheight / 2 + params->win_height / 2;		
		dda.linevec.x = dda.linevec.x < 0 ? 0 : dda.linevec.x;
		dda.linevec.y = dda.lineheight / 2 + params->win_height / 2;		
		dda.linevec.y = dda.linevec.y >= params->win_height ? params->win_height - 1 : dda.linevec.y;

		// TEXTURE

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
			color = texture[64 * texy + texx];
			if (dda.side == 2 || dda.side == 3)
				color = (color >> 1) & 8355711;	
			buffer[b][x] = color;
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

	// SPRITE HANDLING \\
	_____________________

	if (si > 0)
	{
		si = 0;
		while (si < SPRITES_QUANTITY) // set distance
		{
			sprites[si].distance = ((params->posx - sprites[si].x) * (params->posx - sprites[si].x) + (params->posy - sprites[si].y) * (params->posy - sprites[si].y));
			si++;
		}
	}

	if (si > 0) { sort_sprites(sprites, SPRITES_QUANTITY); }
	
	if (si > 0)
		si = 0;
	else
		si = SPRITES_QUANTITY;

	double spritex;
	double spritey;
	double invdet;
	double transformx;
	double transformy;
	int spritescreenx;
	int spriteheight;
	int spritewidth;
	int dsx;
	int dsy;
	int dey;
	int dex;
	int sy;
	int d;
	int *stex = params->stex;

	while (si < SPRITES_QUANTITY)
	{
		spritex = sprites[si].x - params->posx;
		spritex = sprites[si].y - params->posy;
		
		invdet = 1.0 / (params->planex * params->diry - params->dirx * params->planey);
		transformx = invdet * (params->diry * spritex - params->dirx * spritey);
		transformy = invdet * (-params->planey * spritex + params->planex * spritey);
	
		spritescreenx = (int)((params->win_width / 2) * (1 + transformx / transformy));
	
		spriteheight = abs((int)(params->win_height / (transformy)));
		dsy = -spriteheight / 2 + params->win_height / 2;	
		if (dsy < 0)
			dsy = 0;
		dey = spriteheight / 2 + params->win_height / 2;	
		if (dey >= params->win_height)
			dey = params->win_height - 1;
	
		spritewidth = abs((int)(params->win_height / (transformy))); // Same as sprite height ?
		dsx = -spritewidth / 2 + spritescreenx;	
		if (dsx < 0)
			dsx = 0;
		dex = spritewidth / 2 + spritescreenx;
		if (dex >= params->win_width)
			dex = params->win_width - 1;	
		
		while (dsx < dex)
		{
			texx = (int)(256 * (dsx - (-spritewidth / 2 + spritescreenx)) * 64 / spritewidth) / 256;

			if (transformy > 0 && dsx > 0 && dsx < params->win_width && transformy < zbuffer[dsx])
			{
				sy  = dsy;
				while (sy < dey)
				{
					d = sy * 256 - params->win_height * 128 + spriteheight * 128;
					texy = ((d * 64) / spriteheight) / 256;
					color = stex[64 * texy * texx];
					if (color != 0)
						buffer[sy][dsx] = color;
					sy++;
				}
			}
			dsx++;
		}

		si++;
	}	

	buffer_to_image(params->win_height, params->win_width, buffer, &params->img);
	mlx_put_image_to_window(params->mlx_id, params->win_id, params->img_id, 0, 0);
	mlx_clear_img(&(params->img));
}
