#include "header.h"

int	validate_map(t_parameters *params)
{
	int i;
	int h;
	int w;

	if (validate_line_type1((params->map)[0], params->map_w) == 0)
		return (0);
	h = 1;
	while (h < params->map_h && params->map && (params->map)[h])
	{
		i = 0;
		while ((w = ft_index("012NSEW", (params->map)[h][i])) > -1)
		{
			if (w > 2 && params->posx == 0)
				set_player_position(params, w, h, i);
			else if (w > 2 && params->posx != 0)
				return (0);
			i++;
		}
		if (i != params->map_w)
			return (0);
		if ((params->map)[h][0] != '1' || (params->map)[h][i - 1] != '1')
			return (0);
		h++;
	}
	// if player position not found invalid
	if (validate_line_type1((params->map)[h - 1], params->map_w) == 0)
		return (0);
	return (1);
}
