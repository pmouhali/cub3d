#include "header.h"

void    set_resolution(t_parameters *params, const char *line)
{
	int i;

	if (params->win_w != 0 || params->win_h != 0) 
		quit_program(params, "Resolution has already been set.");
	params->win_w = ft_atoi(line);
	if (params->win_w > MAX_WINDOW_WIDTH) 
		params->win_w = MAX_WINDOW_WIDTH;
	if (params->win_w < 1)
		quit_program(params, "Can't run a window with given width.");
	i = 0;
	while (line[i] == 32)
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	params->win_h = ft_atoi(&line[i]);
	if (params->win_h > MAX_WINDOW_HEIGHT)
		params->win_h = MAX_WINDOW_HEIGHT;
	if (params->win_h < 1)
		quit_program(params, "Can't run a window with given height.");
}
