#include "header.h"

void    init_params(t_parameters *params, const char *filepath)
{
	int fd;
	int i;
	char *line = NULL;

	set_params_to_default(params);
	if (ft_strcmp(ft_strrchr(filepath, '.'), ".cub"))
		quit_program(params, "Error: not a .cub file.");
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		quit_program(params, "Error: can't open file.");
	params->fd = fd;
	while ((i = get_next_line(fd, &line)))
	{
		i = 0;
		while (line[i] == 32)
			i++;
		if (line[i] && ft_isalpha(line[i]))
			set_params(params, &line[i]);
		else if (line[i] && line[i] == '1') // check if config is ok
			params->map_h += 1;
		free(line);
	}
	set_map(params, &line);
	free(line);
	close(fd);
}

