#include "header.h"

void    init_params(t_parameters *params, const char *filepath)
{
	int i;
	int l;
	char *line = NULL;

	set_params_to_default(params);
	validate_file(params, filepath);
	l = 0;
	while ((i = get_next_line(params->fd, &line)))
	{
		i = 0;
		while (line[i] == 32)
			i++;
		if (line[i] && ft_isalpha(line[i]))
			set_params(params, &line[i]);
		else if (line[i] && line[i] == '1') // check if config is ok
			params->map_h += 1;
		l = params->map_h > 0 ? l : l + 1;
		free(line);
	}
	set_map(params, &line, l);
	free(line);
	close(params->fd);
}
