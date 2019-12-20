Etant donne une map fixe, une position x:y, une resolution x:y
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
