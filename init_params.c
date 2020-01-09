#include "header.h"

void    init_params(t_parameters *params, const char *filepath)
{
	int fd;
	int i;
	int l;
	char *line = NULL;

	set_params_to_default(params);
	fd = validate_file(params, filepath);
	l = 0;
	while ((i = get_next_line(fd, &line)))
	{
		i = 0;
		while (line[i] == 32)
			i++;
		if (line[i] && ft_isalpha(line[i]))
			set_params(params, &line[i]);
		else if (line[i] && line[i] == '1')
			params->map_h += 1;
		l = params->map_h > 0 ? l : l + 1;
		free(line);
	}
	free(line);
	close(fd);
	set_map(params, &line, l);
	// if (validate_config(params) == 0)
	// 	quit_program(params, "Error: configuration incomplete.");
}
