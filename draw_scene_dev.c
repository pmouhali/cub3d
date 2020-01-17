#include "header.h"
#include <stdio.h>

/*
** init other params ((p.sprites), buffers)
** init dda
** perform dda
** apply texture to buffer with dda infos
** apply (p.sprites)
*/

int	**draw_scene(t_parameters p)
{
	t_dda_parameters dda;
	int **buffer;
	int x = 0;
	
	if (!(buffer = (int**)new_tda(sizeof(int), p.win_h, p.win_w)))
		return (NULL);

	int b = 0;

	// textures
	int texx;
	int texy;
	int color;

	// (p.sprites)
// TODO: VLA interdit, utiliser un double pointeur alloué
	double zbuffer[p.win_w];

	// START RAYCASTING LOOP
	while (x < p.win_w)
	{
		dda_init(p, &dda, x);
		dda_perform(&dda, p.map);

		// DDA SET DISTANCES AND DRAW START AND ENDS
		if (dda.side == NORTH || dda.side == SOUTH)
			dda.perpwalldist = (dda.mapx - p.posx + (1 - dda.stepx) / 2) / dda.raydirx;	
		else
			dda.perpwalldist = (dda.mapy - p.posy + (1 - dda.stepy) / 2) / dda.raydiry;	

		zbuffer[x] = dda.perpwalldist; 

		dda.lineheight = (int)(p.win_h / dda.perpwalldist);

		dda.linex = -dda.lineheight / 2 + p.win_h / 2;		
		dda.linex = dda.linex < 0 ? 0 : dda.linex;
		dda.liney = dda.lineheight / 2 + p.win_h / 2;		
		dda.liney = dda.liney >= p.win_h ? p.win_h - 1 : dda.liney;

		if (dda.side == NORTH || dda.side == SOUTH)
			dda.wallx = p.posy + dda.perpwalldist * dda.raydiry;
		else
			dda.wallx = p.posx + dda.perpwalldist * dda.raydirx;
		dda.wallx -= floor(dda.wallx);
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
			color = (int)((texture.img)[texture.height * texy + texx]);
// TODO: le sujet demande pas d'assombrir les murs.. 
	//		if (dda.side == WEST || dda.side == EAST)
	//			color = (color >> 1) & 8355711;	
			buffer[b][x] = color;
			b++;
		}
		if (dda.linex > 0)
		{
			b = 0;
			while (b < dda.linex)
			{
				buffer[b][x] = p.floor_color;
				b++;
			}
		}
// TODO: corriger le segfault en se basant sur le resultat live de la position 
		if (dda.liney < p.win_h - 1)
		{
			b = dda.liney;
			while (b < p.win_h - 1)
			{
				buffer[b][x] = p.ceiling_color; // SEGV si joueur entre 2 murs
				b++;
			}
		}

		x++;
	}

	// SPRITE HANDLING after raycasting loop 

	// set distance

	b = 0;
	while (b < p.nsprite)	{
		(p.sprites)[b].distance = ((p.posx - (p.sprites)[b].x) * (p.posx - (p.sprites)[b].x) + (p.posy - (p.sprites)[b].y) * (p.posy - (p.sprites)[b].y));
		b++;
	}
	sort_sprites(p.sprites, p.nsprite);

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
	int *stex = p.sprite_texture.img;
	int si;
	
	si = 0;
	while (si < p.nsprite)
	{
		spritex = (p.sprites)[si].x - p.posx + 0.5;
		spritey = (p.sprites)[si].y - p.posy + 0.5;
		
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
			if (transformy > 0 && dsx > 0 && dsx < p.win_w && transformy < zbuffer[dsx])
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

// TODO: free tout les elements alloués !! 
	return (buffer);
}
