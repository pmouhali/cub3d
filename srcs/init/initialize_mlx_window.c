#include "header.h"

void	initialize_mlx_window(t_parameters *p)
{
	p->win_id = mlx_new_window(p->mlx_id, p->win_w, p->win_h, "cub3d");
	if (!p->win_id)
		quit_program(p, "Mlx failed to return a window identifier.");
	p->img_id = mlx_new_image(p->mlx_id, p->win_w, p->win_h);
	if (!p->img_id)
		quit_program(p, "Mlx failed to return an image identifier.");
	p->img = mlx_get_data_addr(
		p->img_id, 
		&(p->bpp),
		&(p->line_size),
		&(p->endian)
	);
}
