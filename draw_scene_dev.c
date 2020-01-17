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

	double *zbuffer;

	if (!(zbuffer = (double*)malloc(sizeof(double) * p.win_w)))
		return (NULL);

	// START RAYCASTING LOOP
	while (x < p.win_w)
	{
		dda_init(p, &dda, x);
		dda_perform(&dda, p.map);
		dda_data(&dda, p, &zbuffer[x]);
		draw_textured_stripe(buffer, x, dda, p);
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
	free(zbuffer);
// TODO: free tout les elements alloués !! 
	return (buffer);
}
