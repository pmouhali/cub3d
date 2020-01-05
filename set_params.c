#include "header.h"

void    set_params(t_parameters *params, const char *line)
{
	if (line[0] == 'R' && line[1] == ' ')		
		set_resolution(params, &line[2]);
		/*
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')		
		set_north_texture(params, &line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')		
		set_south_texture(params, &line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')		
		set_west_texture(params, &line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')		
		set_east_texture(params, &line[2]);
	else if (line[0] == 'S' && line[1] == ' ')		
		set_sprite_texture(params, &line[2]);
		*/
	else if (line[0] == 'F' && line[1] == ' ')		
		set_floor_color(params, &line[2]);
	else if (line[0] == 'C' && line[1] == ' ')		
		set_ceiling_color(params, &line[2]);
	else
		quit_program(params, "Error : unknown configuration identifier.");
}
