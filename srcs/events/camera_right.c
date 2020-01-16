#include "header.h"

void	camera_right(t_parameters *p)
{
	double olddirx;
	double oldplanex;

	olddirx = p->dirx;
	p->dirx = p->dirx * cos(-ROTSPEED) - p->diry * sin(-ROTSPEED);
	p->diry = olddirx * sin(-ROTSPEED) + p->diry * cos(-ROTSPEED);
	oldplanex = p->planex;
	p->planex = p->planex * cos(-ROTSPEED) - p->planey * sin(-ROTSPEED);
	p->planey = oldplanex * sin(-ROTSPEED) + p->planey * cos(-ROTSPEED);
}
