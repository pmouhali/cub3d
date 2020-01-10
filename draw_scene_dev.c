#include "header.h"
#include <stdio.h>

// TODO: la fonction buffer_to_image() doit s'adapter au double pointer ! 

// TODO: cette fonction n'est pas autorisée à modifier les paramètres donc 
// TODO: elle devra recevoir une simple copie et non un pointeur 
// TODO: tout redecouper en fonctions : 
/*
** init other params (sprites, buffers)
** init dda
** perform dda
** apply texture to buffer with dda infos
** apply sprites
*/

int	**draw_scene(t_parameters p)
{
	int **buffer;
	int x = 0;
	
	if (!(buffer = (int**)new_tda(sizeof(int), p.win_h, p.win_w)))
		return (NULL);
	t_dda_parameters dda;

	int b = 0;

	// textures
	int texx;
	int texy;
	int color;
/*
	// sprites
// TODO: VLA interdit, utiliser un double pointeur alloué
	double zbuffer[p.win_w];

// TODO: VLA interdit, utiliser un double pointeur alloué
	t_sprite sprites[SPRITES_QUANTITY];
	int si = 0;
	int sprites_infov;
// TODO: faire une fonction
	while (si < SPRITES_QUANTITY)
	{
		sprites[si].x = 0;
		sprites[si].y = 0;
		sprites[si].distance = 0.0;
		si++;
	}
	si = 0;
*/
	
	// START RAYCASTING LOOP
	while (x < p.win_w - 1)
	{
		dda.camerax = 2 * x / (double)p.win_w - 1;
		dda.raydirx = p.dirx + p.planex * dda.camerax;
		dda.raydiry = p.diry + p.planey * dda.camerax;
		dda.mapx = (int)p.posx;
		dda.mapy = (int)p.posy;
		dda.hit = 0;
	
		dda.deltadistx = fabs(1 / dda.raydirx);
		dda.deltadisty = fabs(1 / dda.raydiry);

		if (dda.raydirx < 0)
		{
			dda.stepx = -1;
			dda.sidedistx = (p.posx - dda.mapx) * dda.deltadistx;
		}
		else
		{
			dda.stepx = 1;
			dda.sidedistx = (dda.mapx + 1.0 - p.posx) * dda.deltadistx;
		}
		if (dda.raydiry < 0)
		{
			dda.stepy = -1;
			dda.sidedisty = (p.posy - dda.mapy) * dda.deltadisty;
		}
		else
		{
			dda.stepy = 1;
			dda.sidedisty = (dda.mapy + 1.0 - p.posy) * dda.deltadisty;
		}
		while (dda.hit == 0)
		{
			if (dda.sidedistx < dda.sidedisty)
			{
				dda.sidedistx += dda.deltadistx;
				dda.mapx += dda.stepx;
				if (dda.raydirx < 0)
					dda.side = NORTH;
				else
					dda.side = SOUTH;
			}
			else
			{
				dda.sidedisty += dda.deltadisty;
				dda.mapy += dda.stepy;
				if (dda.raydiry < 0)
					dda.side = WEST;
				else
					dda.side = EAST;
			}
			if ((p.map)[dda.mapx][dda.mapy] == '1')
				dda.hit = 1;
// TODO: corriger le bug, essayer de faire un truc pas trop lent
/*
			else if ((p.map)[dda.mapx][dda.mapy] == 2
				&& si < SPRITES_QUANTITY - 1  &&
					(sprites[si].x != dda.mapx
						|| sprites[si].y != dda.mapy))
			{
				si++;
				sprites[si].x = dda.mapx;
				sprites[si].y = dda.mapy;
			}
	*/
		}

		if (dda.side == NORTH || dda.side == SOUTH)
			dda.perpwalldist = (dda.mapx - p.posx + (1 - dda.stepx) / 2) / dda.raydirx;	
		else
			dda.perpwalldist = (dda.mapy - p.posy + (1 - dda.stepy) / 2) / dda.raydiry;	

//		zbuffer[x] = dda.perpwalldist; 

		dda.lineheight = (int)(p.win_h / dda.perpwalldist);

		dda.linex = -dda.lineheight / 2 + p.win_h / 2;		
		dda.linex = dda.linex < 0 ? 0 : dda.linex;
		dda.liney = dda.lineheight / 2 + p.win_h / 2;		
		dda.liney = dda.liney >= p.win_h ? p.win_h - 1 : dda.liney;

		// TEXTURE
// TODO: determier la texture a utiliser en fonction de 1 2 ou 3
// TODO: on aura besoin de ses dimensions  propres
		t_texture	texture;

		if (dda.side == NORTH)
			texture = p.north_texture;
		if (dda.side == SOUTH)
			texture = p.south_texture;
		if (dda.side == WEST)
			texture = p.west_texture;
		if (dda.side == EAST)
			texture = p.east_texture;

		if (dda.side == NORTH || dda.side == SOUTH)
			dda.wallx = p.posy + dda.perpwalldist * dda.raydiry;
		else
			dda.wallx = p.posx + dda.perpwalldist * dda.raydirx;
		dda.wallx -= floor(dda.wallx);
		
		texx = (int)(dda.wallx * (double)texture.width);
		if ((dda.side == NORTH  || dda.side == SOUTH) && dda.raydirx > 0)
			texx = (double)texture.width - texx - 1;
		if ((dda.side == WEST || dda.side == EAST) && dda.raydiry < 0)
			texx = (double)texture.width - texx - 1;
		
		double step = 1.0 * texture.height / dda.lineheight;
		double texpos = (dda.linex - p.win_h / 2 + dda.lineheight / 2) * step;
		b = dda.linex;
// TODO: decouper en trois fonctions (print wall, floor, and ceiling)
		while (b < dda.liney)
		{
			texy = (int)texpos & (texture.height - 1);
			texpos += step;
			color = (texture.img)[texture.height * texy + texx];
// TODO: le sujet demande pas d'assombrir les murs.. 
	//		if (dda.side == WEST || dda.side == EAST)
	//			color = (color >> 1) & 8355711;	
			buffer[b][x] = color;
			b++;
		}
		if (dda.linex > 0) // CEILING
		{
			b = 0;
			while (b < dda.linex)
			{
				buffer[b][x] = p.ceiling_color;
				b++;
			}
		}
		if (dda.liney < p.win_h - 1) // FLOOR
		{
			b = dda.liney;
			while (b < p.win_h - 1)
			{
				buffer[b][x] = p.floor_color;
				b++;
			}
		}

		x++;
	}
/*
	// SPRITE HANDLING after raycasting loop 

	sprites_infov = si + 1;
	
	si = 0;
	while (si < sprites_infov) // set distance
	{
		sprites[si].distance = ((p.posx - sprites[si].x) * (p.posx - sprites[si].x) + (p.posy - sprites[si].y) * (p.posy - sprites[si].y));
		si++;
	}

	if (sprites_infov > 0)
		sort_sprites(sprites, sprites_infov);
	si = 0;
	while (si < sprites_infov)
	{
		printf("sprite%d x%f, y%f, d%f\n", si, sprites[si].x, sprites[si].y, sprites[si].distance);
		si++;
	}

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
	int *stex = p.sprite_texture;
	
	si = 0;
	while (si < sprites_infov)
	{
		spritex = sprites[si].x - params->posx;
		spritey = sprites[si].y - params->posy;
		
		invdet = 1.0 / (p.planex * p.diry - p.dirx * p.planey);
		transformx = invdet * (p.diry * spritex - p.dirx * spritey);
		transformy = invdet * (-p.planey * spritex + p.planex * spritey);
	
		spritescreenx = (int)((p.win_w / 2) * (1 + transformx / transformy));
	
		spriteheight = abs((int)(p.win_h / (transformy)));
		dsy = -spriteheight / 2 + p.win_h / 2;	
		if (dsy < 0)
			dsy = 0;
		dey = spriteheight / 2 + p.win_h / 2;	
		if (dey >= p.win_h)
			dey = p.win_h - 1;
	
		spritewidth = abs((int)(p.win_h / (transformy))); // Same as sprite height ?
		dsx = -spritewidth / 2 + spritescreenx;	
		if (dsx < 0)
			dsx = 0;
		dex = spritewidth / 2 + spritescreenx;
		if (dex >= p.win_w)
			dex = p.win_w - 1;	
		
		while (dsx < dex)
		{
			texx = (int)(256 * (dsx - (-spritewidth / 2 + spritescreenx)) * 64 / spritewidth) / 256;

			if (dsx > 0 && dsx < p.win_w && transformy < zbuffer[dsx])
			{
				sy  = dsy;
				while (sy < dey)
				{
					d = (sy) * 256 - p.win_h * 128 + spriteheight * 128;
					texy = ((d * 64) / spriteheight) / 256;
					color = stex[64 * texy + texx];
					if (color != 0)
						buffer[sy][dsx] = color;
					sy++;
				}
			}
			dsx++;
		}

		si++;
	}
	*/

// TODO: free tout les elements alloués !! 
	return (buffer);
}
