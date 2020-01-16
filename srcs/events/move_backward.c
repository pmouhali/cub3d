#include "header.h"

void	move_forward(t_parameters *p)
{
	if (p->map[(int)(p->posx + p->dirx * MOVESPEED)][(int)p->posy] == '0')
		p->posx += p->dirx * MOVESPEED;
	if (p->map[(int)p->posx][(int)(p->posy + p->diry * MOVESPEED)] == '0')
		p->posy += p->diry * MOVESPEED;
}
