#include "header.h"

int		validate_line_type1(char *map_line, int len)
{
	int i;

	i = 0;
	while (map_line[i] == '1')
		i++;
	if (i != len)
		return (0);
	return (1);
}
