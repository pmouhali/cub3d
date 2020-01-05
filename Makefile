SRCS = 	get_next_line_utils.c \
		get_next_line.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_index.c \
		ft_strcmp.c \
		quit_program.c \
		init_params.c \
		ft_putendl_fd.c \
		ft_isalpha.c \
		set_params_to_default.c \
		set_params.c \
		set_resolution.c \
		set_floor_color.c \
		set_ceiling_color.c \
		ft_atoi.c \

all:
		gcc -I./ $(SRCS)  main.c -o cub3d
