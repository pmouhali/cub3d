#include "header.h"

void	dda_perform(t_dda_parameters *dda, char **map)
{
	dda->hit = 0;
	while (dda->hit == 0)
	{                                     
		if (dda->sidedistx < dda->sidedisty)
		{                                   
			dda->sidedistx += dda->deltadistx;
			dda->mapx += dda->stepx;
			dda->side = dda->raydirx < 0 ? NORTH : SOUTH;
		}   
		else                                
		{                                   
			dda->sidedisty += dda->deltadisty;
			dda->mapy += dda->stepy;
			dda->side = dda->raydiry < 0 ? WEST : EAST;
		}                                      
		if (map[dda->mapx][dda->mapy] == '1')             
			dda->hit = 1; 
	}
}
