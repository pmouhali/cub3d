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
	free(*line);
	if (i != w)
		quit_program(params, "Error : map must be closed by walls.");
	h = 1;
	while((i = get_next_line(fd, *line)) && h += 1)
	{
		tmp = params->map;
		params->map = malloc(sizeof(char*) * (h + 1));
		i = -1;
		while (++i < h - 1)
			(params->map)[i] = tmp[i];
		// free_2darray(tmp, h - 1); careful with h - 1 maybe wrong calcul
		// (params->map)[i] = set_map_line(*line, w, h - 1); h-1 pour pouvoir free all en cas de fail
		(params->map)[h] = NULL;
		free(*line);
	}
	i = 0;
	while ((params->map)[h - 1][i] == '1')
		i++;
	free(*line);
	if (i != w)
		quit_program(params, "Error : map must be closed by walls.");
}
