#include "header.h"

void	set_map(t_parameters *params, char **line)
{
	int ret;
	int h;
	char **tmp;

	if (params->map_h < 3)
		quit_program(params, "Error: map: not enough height.");
	if (!(tmp = malloc(sizeof(char*) * params->map_h)))
		quit_program(params, "Error: map: malloc failed.");
	h = 0;
	while ((ret = get_next_line(params->fd, line)))
	{
		ret = 0;
		while (ft_index("012NSEW", (*line)[ret]) > -1)
			ret++;
		tmp[h] = ft_strndup(*line, ret);
		h++;
		free(*line);	
	}
	free(*line);	
}








/*
	int i;
	int w;
	char **tmp;

	w = ft_strlen(*line);
	i = 0;
	while ((*line)[i] == '1')
		i++;
	if (i != w)
		quit_program(params, "Error: map must be closed by walls.");
	params->map_h = 1;
	if (!(params->map = malloc(sizeof(char*) * (params->map_h))))
		quit_program(params, "Error: map: malloc failed.");
	(params->map)[0] = ft_strndup(*line, i);
	free(*line);
	while((i = get_next_line(fd, line)))
	{
		if (!validate_map_line(params, *line, w, params->map_h))
		{
			free(*line);
			quit_program(params, "Error: invalid map line.");
		}
		params->map_h += 1;
		tmp = params->map;
		if (!(params->map = malloc(sizeof(char*) * (params->map_h))))
			quit_program(params, "Error: map: malloc failed.");
		i = -1;
		while (++i < params->map_h - 1)
			(params->map)[i] = tmp[i];

		free_tda((void**)tmp, params->map_h - 1);

		(params->map)[i] = ft_strndup(*line, ft_strlen(*line));
		free(*line);
	}
	i = 0;
	while ((params->map)[params->map_h - 1][i] == '1')
		i++;
//	free(*line);
	if (i != w)
		quit_program(params, "Error: map must be closed by walls.");
*/
