#include "bitmapfile.h"

void	write_bmpfileheader(int fd, t_bitmapfileheader bmpfh)
{
	unsigned char buf[14];

	buf[0] = bmpfh.filetype.d[0];
	buf[1] = bmpfh.filetype.d[1];
	dint4cpy(bmpfh.filesize, &buf[2]);
	dint4cpy(bmpfh.reserved, &buf[6]);
	dint4cpy(bmpfh.pixeldata_offset, &buf[10]);
	write(fd, buf, 14);
}
