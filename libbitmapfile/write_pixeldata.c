#include "bitmapfile.h"

int		write_pixeldata(int fd, t_bitmapinfoheader bih, int **img)
{
	int x;
	int y;
	int i;
	unsigned char *buf;

	i = bih.bpp.i / 8;
	bih.img_size.i = (i * bih.img_width.i) * (i * bih.img_width.i);
	if (!(buf = malloc(sizeof(unsigned char) * (i + 1))))
		return (-1);
	x = -1;
	i = 0;
	while (++x < bih.img_height.i && (y = -1))
	{
		while (++y < bih.img_width.i)
		{
			bih.totalcolors.i = img[x][y];
			buf[i] = bih.totalcolors.d[0];
			buf[i + 1] = bih.totalcolors.d[1];
			buf[i + 2] = bih.totalcolors.d[2];
			buf[i + 3] = bih.totalcolors.d[3];
			i += bih.bpp.i / 8;
		}
	}
	write(fd, buf, bih.img_size.i);
	free(buf);
	return (0);
}
