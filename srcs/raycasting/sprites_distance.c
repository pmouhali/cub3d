#include "header.h"

void	sprites_distance(t_sprite *sprites, int size, int posx, int posy)
{
	int i;

	i = 0;
	while (i < size)
	{
		sprites[i].distance = 
			((posx - sprites[i].x) * (posx - sprites[i].x)
			+ (posy - sprites[i].y) * (posy - sprites[i].y));
		i++;
	}
}
