#include "bitmapfile.h"

void	dint4cpy(t_dint4 n, unsigned char *dest)
{
	dest[0] = n.d[0];
	dest[1] = n.d[1];
	dest[2] = n.d[2];
	dest[3] = n.d[3];
}
