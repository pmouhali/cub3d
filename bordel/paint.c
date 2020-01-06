#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct	s_rgba
{
		unsigned int	r;
		unsigned int	g;
		unsigned int	b;
		unsigned int	a;
}		t_rgba;

typedef struct	s_line
{
	int x; // on screen width, x position of the first point
	int y; // on screen height, y position of the firt point
	int z; // on screen height, y position of the second point
}		t_line;

typedef struct	s_parameters
{
	int keycode;
	int posx;
	int posy;
	void *mlx;
	void *win;
	void *img;
	void *img_tab;
	t_rgba color;
}		t_parameters; // current position and keycode hitted

void	mlx_img_draw_vertical_line(void **img, t_line line, t_rgba color)
{
	int i;
	int pp;
	unsigned char *c;

	i = line.y;
	c = *img;
	while (i != line.z)
	{
		pp = line.x * 4 + 4 + 3200 * i;
		printf("pp = %d\n", pp);
		c[pp] = color.r;	
		c[pp + 1] = color.g;	
		c[pp + 2] = color.b;	

		i++;
	}
}

void	mlx_img_draw_pixel(void **img, int x, int y, t_rgba color)
{
	int pp;
	unsigned char *c;

	c = *img;
	pp = x * 4 + 4 + 3200 * y;
	c[pp] = color.r;	
	c[pp + 1] = color.g;	
	c[pp + 2] = color.b;	
}

int	key_hook(int keycode,void *params)
{
	t_parameters *copy;

	copy = params;
	copy->keycode = keycode;
	if (keycode == 123)
		copy->posx -= 1;
	if (keycode == 124)
		copy->posx += 1;
	if (keycode == 125)
		copy->posy += 1;
	if (keycode == 126)
		copy->posy -= 1;

	char *t;
	t = copy->img_tab;

	mlx_img_draw_pixel((void**)&t, copy->posx, copy->posy, copy->color);
	mlx_put_image_to_window(copy->mlx, copy->win, copy->img, 0, 0);
	
	if (copy->keycode == 53)
		exit(1);
	return (0);
}

int	main(void)
{
	void *id;
	void *window_id;

	id = mlx_init();
	window_id = mlx_new_window(id, 800, 600, "test");

	void *img;
	void *test;
	int bpp;
	int size_line;
	int endian;

	img = mlx_new_image(id, 800, 600);
	test = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	printf("bpp = %d\n", bpp);
	printf("size_line = %d\n", size_line);
	printf("endian = %d\n", endian);
	
	unsigned char *cimg;
	cimg = test;

	t_line line;
	t_rgba color;

	line.x = 200;
	line.y = 0;
	line.z = 400;

	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 0;

	t_parameters params;
	
	params.posx = 400;
	params.posy = 400;

	params.mlx = id;
	params.win = window_id;
	params.img = img;
	params.img_tab = test;
	params.color = color;

//	mlx_key_hook(window_id, &key_hook, &params);
	mlx_hook(window_id, 2, 0, &key_hook, &params);		
	mlx_loop(id);
	return (0);
}
