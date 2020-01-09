#include "bitmapfile.h"

static void	set_bmpinfoheader(t_bitmapinfoheader *bmpih, int bwidth, int bheight)
{
	bmpih->headersize.i = 40;
	bmpih->img_width.i = bwidth;
	bmpih->img_height.i = bheight;
	bmpih->planes.i = 1;
	bmpih->bpp.i = 32;
	bmpih->compression.i = 0;
	bmpih->img_size.i = 0;
	bmpih->xpixelspermeter.i = 0;
	bmpih->ypixelspermeter.i = 0;
	bmpih->totalcolors.i = 0;
	bmpih->importantcolors.i = 0;
}

static void	set_bmpfileheader(t_bitmapfileheader *bmpfh, t_bitmapinfoheader	bmpih)
{
	unsigned int bpp;

	bpp = bmpih.bpp.i / 8;
	bmpfh->filetype.i = 19778;
	bmpfh->filesize.i = 54 + ((bpp * bmpih.img_width.i) * (bpp * bmpih.img_height.i));
	bmpfh->reserved.i = 0;
	bmpfh->pixeldata_offset.i = 54;
}

int			create_bmpfile(const char *filepath, int width, int height, const unsigned char **buffer)
{
	int fd;
	t_bitmapfileheader	bmpfh;
	t_bitmapinfoheader	bmpih;

	if ((fd = open(filepath, O_CREAT, O_RDWR, O_APPEND)) < 3)
		return (-1);
	set_bmpinfoheader(&bmpih, width, height);
	set_bmpfileheader(&bmpfh, bmpih);
	write_bmpfileheader(fd, bmpfh);
	write_bmpinfoheader(fd, bmpih);
	if (write_pixeldata(fd, bmpih, buffer) == -1)
		return (-1);
	close(fd);
	return (0);
}
