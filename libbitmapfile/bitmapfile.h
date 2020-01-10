#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef union	u_dint2
{
	int	i;
	unsigned char d[2];
}				t_dint2;

typedef union	u_dint4
{
	int	i;
	unsigned char d[4];
}				t_dint4;

typedef struct	s_bitmapfileheader
{
	t_dint2			filetype;
	t_dint4			filesize;
	t_dint4			reserved;
	t_dint4			pixeldata_offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfoheader
{
	t_dint4		headersize;
	t_dint4		img_width;
	t_dint4		img_height;
	t_dint2		planes;
	t_dint2		bpp;
	t_dint4		compression;
	t_dint4		img_size;
	t_dint4		xpixelspermeter;
	t_dint4		ypixelspermeter;
	t_dint4		totalcolors;
	t_dint4		importantcolors;

}				t_bitmapinfoheader;

void    dint4cpy(t_dint4 n, unsigned char *dest);
void    write_bmpinfoheader(int fd, t_bitmapinfoheader bmpih);
void    write_bmpfileheader(int fd, t_bitmapfileheader bmpfh);
int		write_pixeldata(int fd, t_bitmapinfoheader bmpih, int **img);
int		create_bmpfile(const char *filepath, int width, int height, int **buffer);

/* EXEMPLE
int		main(int ac, char **av)
{
	int fd;
	int p = (4 * 20) * (4 * 20);
	unsigned char buf[54 + p];
	t_bitmapfileheader bfh;
	t_bitmapinfoheader bih;

	bfh.filesize.integer = 54 + p;
	bfh.pixeldata_offset.integer = 52;
	bih.headersize.integer = 40;
	bih.img_width.integer = 20;
	bih.img_height.integer = 20;
	bih.bpp.integer = 32;

	buf[0] = 'B'; buf[1] = 'M';
	buf[2] = bfh.filesize.d[0];
	buf[3] = bfh.filesize.d[1];
	buf[4] = bfh.filesize.d[2];
	buf[5] = bfh.filesize.d[3];
	buf[6] = 0; buf[7] = 0; buf[8] = 0; buf[9] = 0;
	buf[10] = bfh.pixeldata_offset.d[0];
	buf[11] = bfh.pixeldata_offset.d[1];
	buf[12] = bfh.pixeldata_offset.d[2];
	buf[13] = bfh.pixeldata_offset.d[3];
	buf[14] = bih.headersize.d[0];
	buf[15] = bih.headersize.d[1];
	buf[16] = bih.headersize.d[2];
	buf[17] = bih.headersize.d[3];
	buf[18] = bih.img_width.d[0];
	buf[19] = bih.img_width.d[1];
	buf[20] = bih.img_width.d[2];
	buf[21] = bih.img_width.d[3];
	buf[22] = bih.img_height.d[0];
	buf[23] = bih.img_height.d[1];
	buf[24] = bih.img_height.d[2];
	buf[25] = bih.img_height.d[3];
	buf[26] = 1; buf[27] = 0;
	buf[28] = bih.bpp.d[0];
	buf[29] = bih.bpp.d[1];
	buf[30] = 0; buf[31] = 0; buf[32] = 0; buf[33] = 0;
	buf[34] = 0; buf[35] = 0; buf[36] = 0; buf[37] = 0;
	buf[38] = 0; buf[39] = 0; buf[40] = 0; buf[41] = 0;
	buf[42] = 0; buf[43] = 0; buf[44] = 0; buf[45] = 0;
	buf[46] = 0; buf[47] = 0; buf[48] = 0; buf[49] = 0;
	buf[50] = 0; buf[51] = 0; buf[52] = 0; buf[53] = 0;

	int x = 0;
	int y;
	t_dint r;
	int i = 54;
	while (x < 20)
	{
		y = 0;
		while (y < 20)
		{
			r.integer = map[x][y];
			buf[i] = r.d[3];
			buf[i + 1] = r.d[2];
			buf[i + 2] = r.d[1];
			buf[i + 3] = r.d[0];
			y++;
			i += 4;
		}
		x++;
	}

	fd = open(av[1], O_RDWR);

	write(fd, buf, 24 + p);
}
*/
