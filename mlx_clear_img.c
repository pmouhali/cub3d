#include "header.h"

void	mlx_clear_img(void **img)
{
	int i = 0;
	unsigned char *c;

	c = *img;
	while (i++ < 1920000)
		c[i] = 0;
}
