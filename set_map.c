#include "header.h"

void	set_map(t_parameters *params, char **line, int l)
{
	int h;
	int fd;
	char **tmp;

	if (params->map_h < 3)
		quit_program(params, "Error: map: not enough height.");
	if (!(tmp = (char**)malloc(sizeof(char*) * params->map_h)))
		quit_program(params, "Error: map: malloc failed.");
	if ((fd = open(params->config_file, O_RDONLY)) < 3)
		quit_program(params, "Error: can't reopen file.");
	h = -1;
	while (++h < l && get_next_line(fd, line))
		free(*line);
	h = -1;
	while (++h < params->map_h && get_next_line(fd, line))
	{
		tmp[h] = ft_strctrim(*line, ' ');
		free(*line);
	}
	close(fd);
	params->map_w = ft_strlen(tmp[0]);
	params->map = tmp;
	if (validate_map(params) == 0)
		quit_program(params, "Error: invalid map.");
}
