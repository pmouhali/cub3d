#include "header.h"

void    init_params(t_parameters *params, const char *filepath)
{
	int fd;

	if (ft_strcmp(ft_strrchr(filepath, '.'), ".cub"))
		quit_program(params, "Error: not a .cub file.");
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		quit_program(params, "Error: can't open file.");
}

