#ifndef HEADER_H
# define HEADER_H

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../get_next_line.h"

#define MAP_AUTHORIZED_CHARACTERS "012NSWE"
#define CONFIGURATION_IDENTIFIERS "RNSWEFC"

typedef struct	s_parameters
{
	int win_h;
	int win_w;
	int map_h;
	int map_w;

	int **map;

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

	void *no_tex_id;
	void *no_tex;
	void *so_tex_id;
	void *so_tex;
	void *ea_tex_id;
	void *ea_tex;
	void *we_tex_id;
	void *we_tex;
	void *sprite_tex_id;
	void *sprite_tex;
	int floor_color;
	int ceiling_color;

}		t_parameters;

void    free_int_tab(int **tab, int array_size);
void    print_int_tab(int **tab, int array_size);
void	quit_program(t_parameters *params);
int		ft_strlen(const char *str);
int     is_file_extension(const char *path, const char *extension);
int     ft_index(char const *s, char c);

#endif
