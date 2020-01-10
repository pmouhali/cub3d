#include "header.h"

void    set_ceiling_color(t_parameters *params, const char *line)
{
	t_dint4 color;
	int i;

	if (params->ceiling_color != -1)
		quit_program(params, "Error: ceiling color has already been set.");
	color.d[2] = ft_atoi(line);
	i = 0;
	while (ft_index(" 0123456789", line[i]) != -1)
		i++;
	i = line[i] == ',' ? i + 1 : i;
	color.d[1] = ft_atoi(&line[i]);
	while (ft_index(" 0123456789", line[i]) != -1)
		i++;
	i = line[i] == ',' ? i + 1 : i;
	color.d[0] = ft_atoi(&line[i]);
	color.d[3] = 0;
	params->ceiling_color = color.i;
}

