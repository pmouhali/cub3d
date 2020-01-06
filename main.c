#include "header.h"
#include <stdio.h> 

int	main(int ac, char **av)
{
	t_parameters params;
	init_params(&params, av[1]);

/*
	params.mlx_id = mlx_init();
	params.win_id = mlx_new_window(params.mlx_id, params.win_width, params.win_height, "test");
	params.img_id = mlx_new_image(params.mlx_id, params.win_width, params.win_height);
	params.img = mlx_get_data_addr(
		params.img_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);

	int pngw;
	int pngh;
	void *tex;

	tex = mlx_png_file_to_image(params.mlx_id, "pics/purplestone.png", &pngw, &pngh);
	params.texture_id = tex;
	params.texture = mlx_get_data_addr(
		params.texture_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);
	void *stex;

	stex = mlx_png_file_to_image(params.mlx_id, "pics/doll.png", &pngw, &pngh);
	params.stex_id = stex;
	params.stex = mlx_get_data_addr(
		params.stex_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);

	draw_scene(&params);

	mlx_hook(params.win_id, 2, 0, &key_hook, &params);		
	mlx_loop(params.mlx_id);
	return (0);
*/
}
