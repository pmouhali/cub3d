#include "header.h"
#include <stdio.h> 

int     mod[20][20] = {
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int	**render_map(void)
{
	int i;
	int j;
	int **map;
	if ((map = (int**)malloc(sizeof(int*) * 20)) == NULL)
		return (map);
	i = 0;
	while (i < 20)
	{
		if ((map[i] = (int*)malloc(sizeof(int) * 20)) == NULL)
			return (map);
		j = 0;
		while (j < 20)
		{
			map[i][j] = mod[i][j];
			j++;
		}	
		i++;
	}
	return (map);
}

int	main(void)
{
	t_parameters params;
	int **tmp;
	tmp = render_map();
	params.win_height = 600;
	params.win_width = 800;
	params.map = tmp;
	print_int_tab(params.map, 20);
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
	void *stex;

	stex = mlx_png_file_to_image(params.mlx_id, "pics/barrel.png", &pngw, &pngh);
	params.stex_id = stex;
	params.stex = mlx_get_data_addr(
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
