#include "header.h"

void	move_left(t_parameters *p)
{
	if ((p->diry < 0 && p->dirx < 0) || (p->diry > 0 && p->dirx > 0))
	{
		if (p->map[(int)(p->posx - p->diry * MOVESPEED)][(int)p->posy] == '0')
			p->posx -= p->diry * MOVESPEED;
		if (p->map[(int)p->posx][(int)(p->posy - p->dirx * MOVESPEED)] == '0')
			p->posy -= p->dirx * MOVESPEED;
	}
	else
	{
		if (p->map[(int)(p->posx + p->diry * MOVESPEED)][(int)p->posy] == '0')
			p->posx += p->diry * MOVESPEED;
		if (p->map[(int)p->posx][(int)(p->posy + p->dirx * MOVESPEED)] == '0')
			p->posy += p->dirx * MOVESPEED;
	}
}
