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
			if (dda->raydirx < 0) 
				dda->side = NORTH;
			else                 
				dda->side = SOUTH;
		}   
		else                                
		{                                   
			dda->sidedisty += dda->deltadisty;
			dda->mapy += dda->stepy;
			if (dda->raydiry < 0)
				dda->side = WEST;
			else                
				dda->side = EAST;               
		}                                      
		if (map[dda->mapx][dda->mapy] == '1')             
			dda->hit = 1; 
	//	else if (map[dda->mapx][dda->mapy] == '2')             
	//		sprite();
	}
}
