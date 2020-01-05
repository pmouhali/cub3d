#include "header.h"

void	set_north_texture(t_parameters *params, const char *line)
{
	// get path without spaces around
	char *path;

	path = ft_strtrim(line, " ");
	printf("path *** %s\n", path);
	free(path);
	// mlx_png if no_tex_id == NULL quit_program "Error: can't load north texture file, it must be a png if you want it to work as expected."
	// get_data_address if no_tex == NULL quit_program "Error: an error as occured after loading north texture."
}
