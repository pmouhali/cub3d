si dirx == -1 : tout fonctionne parfaitement
si dirx == 1  : gauche et droite sont inversees
si diry == -1 : total fucked up
si diry == 1  : total fucked up

  y y y
x 0 1 2
x 1
x 2

joueur regarde au NORD = do not moove
joueur regarde au SUD = key hook left * ?
joueur regarde a l'ouest = key hook left * ?
joueur regarde a l'est = key hook left * ?

FIX : toujours commencer avec le vecteur qui fonctionne puis call keyhook
(sans draw scene) avec le bon moove pour correspondre :)

NORD
dx -1
dy  0
px  0
py  0.66

SUD
dx  1
dy  0
px  0
py -0.66

EST
dx  0
dy  -1
py  0
px  -0.66

OUEST
dx  1
dy  0
py  0
px  0.66






Etant donne une map fixe, une position x:y, une resolution x:y=
{
	L'image s'affiche correctement sans les textures
	Les deplacements sont ok

	L'image s'affiche correctement avec les textures
	Les deplacements sont ok

	L'image s'affiche correctement avec les sprites
	Les deplacements sont ok
}

ESC pour quitter ok
Croix rouge pour quitter ok
--save ok

check map extension ok
assign textures and colors ok
check map ok

error handling ok

(handle error and assign while parsing, exit process if error, careful for leaks)


REQUIREMENTS :

une structure de parametres | this is far from the final struct

typedef struct	s_parameters
{
	void *mlx; // mlx_init() identitfier
	void *win; // mlx_new_window() identifier
	void *img_data; // mlx+new_image() identifier
	void *img; // get_data_addr() addr
	
	int posx; // x position current
	int posy; // y position current

	int keycode; // key pressed

	t_rgba color;

}		t_parameters
