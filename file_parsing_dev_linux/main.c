#include <stdio.h> 
#include "header.h" 

int	main(int ac, char **av)
{
	if (ac < 2) { printf("No input file given\n"); return (0); }
	
	t_parameters params;
	int fd;
	int i;
	char *line;

	fd = open(av[1], O_RDONLY);
	if (fd < 3) { printf("Can't open given file\n"); return (0); }
	while ((i = get_next_line(fd, &line)))
	{
		// parse line
		ret = 0;
		while (line[i] == 32)
			i++;

	}

	return (0);
}
