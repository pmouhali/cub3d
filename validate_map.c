#include "header.h"

int	validate_map(t_parameters *params, char **map)
{
	int i;
	int h;
	int w;

	params->map_w = ft_strlen(map[0]);
	i = 0;
	while (map[0][i] == '1')
		i++;
	if (i != params->map_w)
		return (0);
	h = 1;
	while (h < params->map_h && map && map[h])
	{
		i = 0;
		while ((w = ft_index("012NSEW", map[h][i])) > -1)
		{
			if (w > 2 && params->posx == 0)
				set_player_position(params, w, h, i);
			else if (w > 2 && params->posx != 0)
				return (0);
			i++;
		}
		if (i != params->map_w)
			return (0);
		if (map[h][0] != '1' || map[h][i - 1] != '1')
			return (0);
		h++;
	}
	i = 0;
	while (map[h - 1][i] == '1')
		i++;
	if (i != params->map_w)
		return (0);
	return (1);
}
