#include "header.h"
#include <stdio.h> 

int	main(int ac, char **av)
{
	t_parameters params;
	
	set_params_to_default(&params);	
	params.mlx_id = mlx_init(); // without mlx init, texture setting won't work
	if (!params.mlx_id)
		quit_program(&params, "Minilibx initilization failed.");
	init_params(&params, av[1]);

	if (ac > 2 && ft_strcmp(av[2], "-save") == 0)
	{
		printf("SAVE\n");
	//	save_scene(&params);
	}

/*
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
*/
//	quit_program(&params, "");
}
