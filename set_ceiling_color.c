#include "header.h"

void    set_ceiling_color(t_parameters *params, const char *line)
{
	int r;
	int g;
	int b;

	if (params->ceiling_color != -1)
		quit_program(params, "Error: ceiling color has already been set.");
	r = ft_atoi(line);
	if (r < 0 || r > 255)
		quit_program(params, "Error: ceiling color RGB is out of range.");
	g = 0;
	while (line[g] == 32)
		g++;
	g = line[g] == ',' ? g + 1 : g;
	g = ft_atoi(&line[g]);
	if (g < 0 || g > 255)
		quit_program(params, "Error: ceiling color RGB is out of range.");
	b = 0;
	while (line[b] == 32)
		b++;
	b = line[b] == ',' ? b + 1 : b;
	b = ft_atoi(&line[b]);
	if (b < 0 || b > 255)
		quit_program(params, "Error: ceiling color RGB is out of range.");
	params->ceiling_color = b + 256 * g + 256 * 256 * r;
}

