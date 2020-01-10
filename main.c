#include "header.h"
#include <stdio.h> 

int	main(int ac, char **av)
{
	(void)ac;
	t_parameters params;
	
	init_params(&params, av[1]);
	printf("win_w %d, win_h %d\n", params.win_w, params.win_h);
	printf("map_w %d, map_h %d\n", params.map_w, params.map_h);
	printf("posx %f, posy %f\n", params.posx, params.posy);
	printf("dirx %f, diry %f\n", params.dirx, params.diry);
	printf("planex %f, planey %f\n", params.planex, params.planey);
	printf("floor %d, ceiling %d\n", params.floor_color, params.ceiling_color);
	printf("map :\n");
	int h = 0;
	while (h < params.map_h)
	{
		printf("%s\n", (params.map)[h]);
		h++;
	}
	params.north_texture.img = malloc(sizeof(int) * 4);
	(params.north_texture.img)[0] = 16711935; // NORD == MAGENTA
	(params.north_texture.img)[1] = 16711935;
	(params.north_texture.img)[2] = 16711935;
	(params.north_texture.img)[3] = 16711935;
	params.north_texture.width = 2;
	params.north_texture.height = 2;
	params.south_texture.img = malloc(sizeof(int) * 4);
	(params.south_texture.img)[0] = 16776960; // SUD == JAUNE
	(params.south_texture.img)[1] = 16776960;
	(params.south_texture.img)[2] = 16776960;
	(params.south_texture.img)[3] = 16776960;
	params.south_texture.width = 2;
	params.south_texture.height = 2;
	params.west_texture.img = malloc(sizeof(int) * 4);
	(params.west_texture.img)[0] = 255; // OUEST = BLEU
	(params.west_texture.img)[1] = 255;
	(params.west_texture.img)[2] = 255;
	(params.west_texture.img)[3] = 255;
	params.west_texture.width = 2;
	params.west_texture.height = 2;
	params.east_texture.img = malloc(sizeof(int) * 4);
	(params.east_texture.img)[0] = 16711680;// EST == ROUGE
	(params.east_texture.img)[1] = 16711680;
	(params.east_texture.img)[2] = 16711680;
	(params.east_texture.img)[3] = 16711680;
	params.east_texture.width = 2;
	params.east_texture.height = 2;

	int **buf;
	
	buf = draw_scene(params);
	create_bmpfile("screenshot.bmp", params.win_w, params.win_h, buf);

	free_tda((void**)buf, params.win_h);
	free_tda((void**)params.map, params.map_h);
	free(params.north_texture.img);
	free(params.south_texture.img);
	free(params.east_texture.img);
	free(params.west_texture.img);

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

	if (ac == 3 && ft_strcmp("-save", av[2]) == 0)
	{
		draw_scene(&params, SCREENSHOT);
		quit_program(params, "");
	}
	else
		draw_scene(&params, NO_SCREENSHOT);

	mlx_hook(params.win_id, 2, 0, &key_hook, &params);		
	mlx_loop(params.mlx_id);
	return (0);
*/
}
