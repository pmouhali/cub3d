#include "header.h"

/*
** Check if line only contains authorized characters.
** Check if line lenght is corresponding with first line lenght.
** Check if first and last characters are wall character's.
** Call set_player_position if a N, S, E or W character is found.
** Returns 0 if line is invalid, 1 if line is valid.
*/

int		validate_line_type2(char *map_line, int l, t_parameters *params)
{
		int i;
		int c;

		i = 0;
		while ((c = ft_index("012NSEW", map_line[i])) > -1)
		{
			if (c > 2)
				set_player_position(params, c, l, i);
			i++;
		}
		if (i != params->map_w)
			return (0);
		if (map_line[0] != '1' || map_line[i - 1] != '1')
			return (0);
		return (1);
}
