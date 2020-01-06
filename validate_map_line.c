#include "header.h"

int	validate_map_line(t_parameters *params, char *line, int current_map_w, int current_map_h)
{
	(void)current_map_h;
	(void)params;
	int i;

	i = 0;
	while (ft_index("012NSEW", line[i]) > -1)
		i++;
	if (i != current_map_w)
		return (0);
	
	return (1);
}
