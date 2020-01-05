#include "header.h"

void    init_params(t_parameters *params, const char *filepath)
{
	int fd;
	int i;
	char *line = NULL;

	if (ft_strcmp(ft_strrchr(filepath, '.'), ".cub"))
		quit_program(params, "Error: not a .cub file.");
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		quit_program(params, "Error: can't open file.");
	set_params_to_default(params);
	while ((i = get_next_line(fd, &line)))
	{
		i = 0;
		while (line[i] == 32)
			i++;
		if (line[i] && ft_isalpha(line[i]))
			set_params(params, &line[i]);
		else if (line[i] && line[i] == '1')
		{
			// check if all config is ok
			set_map(params, &line, fd);
		}
		free(line);
	}
	free(line);
	printf("win_w %d, win_h %d\n", params->win_w, params->win_h);
	printf("map_w %d, map_h %d\n", params->map_w, params->map_h);
	printf("posx %f, posy %f\n", params->posx, params->posy);
	printf("dirx %f, diry %f\n", params->dirx, params->diry);
	printf("planex %f, planey %f\n", params->planex, params->planey);
	printf("no_tex %p\n", params->no_tex);
	printf("so_tex %p\n", params->so_tex);
	printf("we_tex %p\n", params->we_tex);
	printf("ea_tex %p\n", params->ea_tex);
	printf("s_tex %p\n", params->s_tex);
	printf("floor %d, ceiling %d\n", params->floor_color, params->ceiling_color);
	close(fd);
}

