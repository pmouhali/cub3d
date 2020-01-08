FLAGS = -Wall -Wextra -Werror

SRCS =	quit_program.c \
		init_params.c \
		validate_file.c \
		set_params_to_default.c \
		set_params.c \
		set_map.c \
		validate_map.c \
		set_resolution.c \
		set_floor_color.c \
		set_ceiling_color.c \
		set_player_position.c \
		validate_line_type1.c \
#		clear_2dbuffer.c \
		mlx_clear_img.c \
		sort_sprites.c \
		buffer_to_image.c \
		keyhook.c \
		set_north_texture.c \


all: comp_libft
	gcc $(FLAGS) -I./ $(SRCS) -g -lz -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit  dev.c main.c -o cub3d

comp_libft:
		cd libft/ && make

dev: comp_libft
	gcc -g $(FLAGS) $(SRCS) main.c -L./libft -lft -o cub3d


