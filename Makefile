SRCS = 	get_next_line_utils.c \
		get_next_line.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_index.c \
		ft_strcmp.c \
		quit_program.c \
		init_params.c \
		ft_putendl_fd.c \
		ft_is_alpha.c \
		set_params.c \
		ft_atoi.c \

all:
		gcc -I./ $(SRCS)  main.c -o cub3d
