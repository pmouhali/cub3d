#include "header.h"
#include <stdio.h> 

int	main(void)
{
	t_parameters params;

	params.win_height = 600;
	params.win_width = 800;
	params.map_width = 20;
	params.map_height = 20;
	params.posx = 2; // real position, not array style position
	params.posy = 2; // real position, not array style position
	params.dirx = 1;
	params.diry = 0;
	params.planex = 0;
	params.planey = -0.66;

	params.mlx_id = mlx_init();
	params.win_id = mlx_new_window(params.mlx_id, params.win_width, params.win_height, "test");
	params.img_id = mlx_new_image(params.mlx_id, params.win_width, params.win_height);
	params.img = mlx_get_data_addr(
		params.img_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);
/*
int tex[64 * 64];
int a = 0;
int b = 0;
while (a < 64)
{
	while (b < 64)
	{
		tex[64 * b + a] = 65536 * 192 * (a % 16 && b % 16);
		b++;
	}
	a++;
	b = 0;
}
*/
	
	int pngw;
	int pngh;
	void *tex;

	tex = mlx_png_file_to_image(params.mlx_id, "pics/bluestone.png", &pngw, &pngh);
	params.texture_id = tex;
	params.texture = mlx_get_data_addr(
		params.texture_id,
		&(params.bpp),
		&(params.size_line),
		&(params.endian)
	);
	draw_scene(&params);

	mlx_hook(params.win_id, 2, 0, &key_hook, &params);		
	mlx_loop(params.mlx_id);
	return (0);
}
