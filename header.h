#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "minilibx_opengl/mlx.h"
#include "libft/libft.h"

typedef struct	s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}	t_rgba;

typedef struct	s_parameters
{
	int fd;
	char *config_file;
	int win_h;
	int win_w;
	int map_h;
	int map_w;
	char **map;

	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;

	int endian;
	int bpp;

	void *mlx_id;
	void *win_id;
	void *img_id;
	int img_size_line;

	void *img;

	void *texture_id; // tmp
	void *texture; // tmp

	void *no_tex_id;
	int no_tex_size_line;
	void *no_tex;
	void *so_tex_id;
	int so_tex_size_line;
	void *so_tex;
	void *we_tex_id;
	int we_tex_size_line;
	void *we_tex;
	void *ea_tex_id;
	int ea_tex_size_line;
	void *ea_tex;
	void *s_tex_id;
	int s_tex_size_line;
	void *s_tex;
	int floor_color;
	int ceiling_color;

}		t_parameters;

typedef struct s_vec
{
	int x;
	int y;
}		t_vec;

typedef struct s_sprite
{
	double x;
	double y;
	double distance;
}		t_sprite;

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

#define SPRITES_QUANTITY 2
#define MOVESPEED 0.16
#define ROTSPEED 0.09

#define MAX_WINDOW_WIDTH 900 // (random, adjust to mac screen)
#define MAX_WINDOW_HEIGHT 900

#define TEST "test"

void	mlx_clear_img(void **img);
void	sort_sprites(t_sprite *sprites, int array_size);
void    draw_scene(t_parameters *tmp);
void    mlx_img_draw_pixel(void **img, int x, int y, t_rgba color);
int     key_hook(int keycode,void *params);
void    clear_2dbuffer(int h, int w, int buf[h][w]);
void    buffer_to_image(int h, int w, int buf[h][w], void **img);
void	quit_program(t_parameters *params, const char *error_msg);
void	init_params(t_parameters *params, const char *filepath);
void    validate_file(t_parameters *params, const char *filepath);

void	set_params_to_default(t_parameters *params);
void	set_params(t_parameters *params, const char *line);
void	set_resolution(t_parameters *params, const char *line);
void	set_north_texture(t_parameters *params, const char *line);
void	set_south_texture(t_parameters *params, const char *line);
void	set_west_texture(t_parameters *params, const char *line);
void	set_east_texture(t_parameters *params, const char *);
void	set_sprite_texture(t_parameters *params, const char *line);
void	set_floor_color(t_parameters *params, const char *line);
void	set_ceiling_color(t_parameters *params, const char *line);
void	set_map(t_parameters *params, char **line, int l);
int			validate_map(t_parameters *params);
void    set_player_position(t_parameters *params, int c, int x, int y);
int		validate_line_type1(char *map_line, int len);

#endif
