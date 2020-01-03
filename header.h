#ifndef HEADER_H
# define HEADER_H

#include <math.h>
#include "minilibx_opengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_rgba;

typedef struct	s_parameters
{
	int win_height;
	int win_width;
	int **map;
	int map_height;
	int map_width;
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	void *mlx_id;
	void *win_id;
	void *img_id;
	int bpp;
	int size_line;
	int endian;
	void *img;
	t_rgba color;
	void *texture_id;
	void *texture;
	void *stex_id;
	void *stex;

}		t_parameters;

typedef struct s_vec
{
	int x;
	int y;
}		t_vec;

typedef struct s_sprite
{
	int x;
	int y;
	double distance;
}		t_sprite;

#define SPRITES_QUANTITY 2
#define MOVESPEED 0.16
#define ROTSPEED 0.09

typedef struct	s_dda_parameters
{
	double camerax;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	int hit;
	int side;
	int lineheight;
	t_vec linevec;
	double wallx;

}		t_dda_parameters;

void	mlx_clear_img(void **img);
void	sort_sprites(t_sprite *sprites, int array_size);
void    draw_scene(t_parameters *tmp);
void    mlx_img_draw_pixel(void **img, int x, int y, t_rgba color);
int     key_hook(int keycode,void *params);
void    free_int_tab(int **tab, int array_size);
void    print_int_tab(int **tab, int array_size);
void    clear_2dbuffer(int h, int w, int buf[h][w]);
void    buffer_to_image(int h, int w, int buf[h][w], void **img);
void	quit_program(t_parameters *params);

#endif
