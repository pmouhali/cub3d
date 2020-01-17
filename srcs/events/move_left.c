#include "header.h"

void	move_left(t_parameters *p)
{
	double ndirx = -p->diry;
	double ndiry = p->dirx;	

	if (p->map[(int)(p->posx + ndirx * MOVESPEED)][(int)p->posy] == '0')
		p->posx += ndirx * MOVESPEED;
	if (p->map[(int)p->posx][(int)(p->posy + ndiry * MOVESPEED)] == '0')
		p->posy += ndiry * MOVESPEED;
}
