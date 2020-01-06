SRCS = 	get_next_line_utils.c \
	get_next_line.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_strctrim.c \
	ft_substr.c \
	ft_strndup.c \
	ft_index.c \
	ft_strcmp.c \
	quit_program.c \
	init_params.c \
	ft_putendl_fd.c \
	ft_isalpha.c \
	set_params_to_default.c \
	set_params.c \
	set_map.c \
	validate_map_line.c \
	set_resolution.c \
	set_floor_color.c \
	set_ceiling_color.c \
	set_north_texture.c \
	ft_atoi.c \
	free_tda.c \
	clear_2dbuffer.c \
	mlx_clear_img.c \
	sort_sprites.c \
	buffer_to_image.c \
	keyhook.c \

all:
	gcc -Wall -Wextra -Werror -I./ $(SRCS) -g -lz -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit  dev.c main.c -o cub3d
