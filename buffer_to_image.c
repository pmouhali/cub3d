#include "header.h"

void	buffer_to_image(int h, int w, int **buf, void **img)
{
	unsigned char *c;
	int pp;
	int a;
	int b;

	c = *img;
	a = 0;
	while (a < h)
	{
		b = 0;
		while (b < w)
		{
			pp = b * 4 + 4 + 3200 * a;
			c[pp + 2] = buf[a][b] / 65536;	
			c[pp + 1] = (buf[a][b] / 256) % 256;	
			c[pp] = buf[a][b] % 256;
			b++;
		}
		a++;
	}
}
