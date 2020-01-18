FLAGS = -Wall -Wextra -Werror

SRCS =	quit_program.c \
		mlx_clear_img.c \
		buffer_to_image.c \
		ft_puterror.c \
		initialize_cub3d.c \
		initialize_mlx_window.c \
		init_params.c \
		validate_params.c \
		set_params_to_default.c \
		save_scene.c \
		display_scene.c \
		srcs/parsing/validate_file.c \
		srcs/parsing/set_params.c \
		srcs/parsing/set_map.c \
		srcs/parsing/validate_map.c \
		srcs/parsing/set_resolution.c \
		srcs/parsing/set_texture.c \
		srcs/parsing/set_floor_color.c \
		srcs/parsing/set_ceiling_color.c \
		srcs/parsing/set_player_position.c \
		srcs/parsing/validate_line_type1.c \
		srcs/parsing/validate_line_type2.c \
		srcs/parsing/set_sprites.c \
		srcs/raycasting/dda_init.c \
		srcs/raycasting/dda_perform.c \
		srcs/raycasting/dda_data.c \
		srcs/raycasting/draw_textured_stripe.c \
		srcs/raycasting/sort_sprites.c \
		srcs/raycasting/sprites_distance.c \
		srcs/raycasting/draw_sprites.c \
		srcs/events/keyhook.c \
		srcs/events/camera_left.c \
		srcs/events/camera_right.c \
		srcs/events/move_forward.c \
		srcs/events/move_backward.c \
		srcs/events/move_left.c \
		srcs/events/move_right.c \

all: comp_libft comp_libbitmapfile comp_mlx
	gcc -g $(FLAGS) $(SRCS) draw_scene_dev.c main.c -lz -L./libmlx -lmlx -framework OpenGL -framework AppKit -I./ -L./libft -lft -L./libbitmapfile -lbitmapfile -o cub3d -lm

comp_libft:
		cd libft/ && make

comp_libbitmapfile:
		cd libbitmapfile/ && make
comp_mlx:
	cd libmlx/ && make

cleanlft:
	cd libft/ && make clean

cleanlbitmapfile:
	cd libbitmapfile/ && make clean

clean: cleanlft cleanlbitmapfile
	rm -f *.bmp cub3d
