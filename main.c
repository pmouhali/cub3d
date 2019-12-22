#include "header.h"
#include <stdio.h> 

int	main(void)
{
	t_parameters params;

	params.win_height = 600;
	params.win_width = 800;
	params.map_width = 10;
	params.map_height = 10;
	params.posx = 1;
	params.posy = 1;
	params.dirx = 0;
	params.diry = 1;
	params.planex = 0;
	params.planey = 0.66;

	params.mlx_id = mlx_init();
	params.win_id = mlx_new_window(params.mlx_id, params.win_width, params.win_height, "test");
	params.img_id = mlx_new_image(params.mlx_id, params.win_width, params.win_height);
	params.img = mlx_get_data_addr(
		params.img_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);

	mlx_hook(params.win_id, 2, 0, &key_hook, &params);		
	mlx_loop(params.mlx_id);
	return (0);
}
