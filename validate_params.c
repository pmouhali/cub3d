#include "header.h"

int		validate_params(t_parameters *params)
{
	if (params->win_h == 0 || params->win_w == 0)
		return (0);
	if (params->map_h < 3 || params->map_w < 3)
		return (0);
	if (params->map == NULL)
		return (0);
	if (params->posx == 0 && params->posy == 0)
		return (0);
	if (params->dirx == 0 && params->diry == 0)
		return (0);
	if (params->planex == 0 && params->planey == 0)
		return (0);
	return (1);
}
