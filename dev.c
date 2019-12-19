#include <math.h>
#include <mlx.h>
#include <stdio.h>

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

	line.x = 400;
	line.y = 0;
	line.z = 600;

	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 0;

	mlx_img_draw_vertical_line(&test, line, color);
	
	mlx_put_image_to_window(id, window_id, img, 0, 0);

	mlx_loop(id);
	return (0);
}
