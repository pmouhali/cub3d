#include "header.h"

void	set_map(t_parameters *params, char **line, int fd)
{
	int i;
	int w;
	int h;

	char **tmp;

	w = ft_strlen(*line);
	i = 0;
	while ((*line)[i] == '1')
		i++;
	if (i != w)
		quit_program(params, "Error: map must be closed by walls.");
	h = 1;
	if ((params->map = (char**)malloc(sizeof(char*) * (h + 1))) == NULL)
		quit_program(params, "Error: malloc failed toallocate map first line.");
	(params->map)[0] = ft_strndup(*line, i);
	(params->map)[1] = NULL;
	free(*line);
	while((i = get_next_line(fd, line)) && h++)
	{
		if (!validate_map_line(params, *line, w, h - 1)) // == 0
		{
			params->map_h = 1;
			free(*line);
			quit_program(params, "Error: invalid map line, can be caused by unknow character, or player position found multiple times.");
		}
		tmp = params->map;
		params->map = malloc(sizeof(char*) * (h + 1));
		i = -1;
		while (++i < h - 1)
			(params->map)[i] = tmp[i];
		(params->map)[h] = NULL;
		free(*line);
	}
	i = 0;
	while ((params->map)[h - 1][i] == '1')
		i++;
	free(*line);
	if (i != w)
		quit_program(params, "Error: map must be closed by walls.");
}
