#include "header.h"

/*
** Check if first line only contains wall's character.
** Check if other lines are valid.
** Check if player position was found.
** Check if last line only contains wall's character.
** Return 0 is the map is invalid, 1 is the map is valid.
*/

int	validate_map(t_parameters *params)
{
	int h;

	if (validate_line_type1((params->map)[0], params->map_w) == 0)
		return (0);
	h = 1;
	while (h < params->map_h && params->map && (params->map)[h])
	{
		if (validate_line_type2((params->map)[h], h, params) == 0)
			return (0);
		h++;
	}
	if (params->posx == 0)
		return (0);
	if (validate_line_type1((params->map)[h - 1], params->map_w) == 0)
		return (0);
	return (1);
}
