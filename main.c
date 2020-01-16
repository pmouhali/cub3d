#include "header.h"
#include <stdio.h> 
/*
static void	print_params(t_parameters p)
{
	printf("resolution: %d x %d\n", p.win_w, p.win_h);
	printf("map: %d x %d\n", p.map_w, p.map_h);
	int i = -1;
	while (++i < p.map_h && p.map && (p.map)[i])
		printf("%s\n", (p.map)[i]);
	printf("start position: x%f y%f\n", p.posx, p.posy);
	printf("direction vector: x%f y%f\n", p.dirx, p.diry);
	printf("camera plane: x%f y%f\n\n", p.planex, p.planey);
	printf("mlx_init(): %p\n", p.mlx_id);
	printf("new_window(): %p\n", p.win_id);
	printf("new_image(): %p\n", p.img_id);
	printf("image bits per pixel: %d\n", p.bpp);
	printf("north_texture id: %p\n", p.north_texture.id);
	printf("north_texture height: %d\n", p.north_texture.height);
	printf("north_texture width: %d\n", p.north_texture.width);
	printf("south_texture id: %p\n", p.south_texture.id);
	printf("south_texture height: %d\n", p.south_texture.height);
	printf("south_texture width: %d\n", p.south_texture.width);
	printf("west_texture id: %p\n", p.west_texture.id);
	printf("west_texture height: %d\n", p.west_texture.height);
	printf("west_texture width: %d\n", p.west_texture.width);
	printf("east_texture id: %p\n", p.east_texture.id);
	printf("east_texture height: %d\n", p.east_texture.height);
	printf("east_texture width: %d\n", p.east_texture.width);
	printf("sprite_texture id: %p\n", p.sprite_texture.id);
	printf("sprite_texture height: %d\n", p.sprite_texture.height);
	printf("sprite_texture width: %d\n", p.sprite_texture.width);
	printf("floor color: %d\n", p.floor_color);
	printf("ceiling color: %d\n", p.ceiling_color);
}
*/

int	main(int ac, char **av)
{
	t_parameters params;
	
	set_params_to_default(&params);	
	params.mlx_id = mlx_init(); // without mlx init, texture setting won't work
	if (!params.mlx_id)
		quit_program(&params, "Minilibx initilization failed.");
	init_params(&params, av[1]);

	if (ac > 2 && ft_strcmp(av[2], "-save") == 0)
		save_scene(&params);

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
