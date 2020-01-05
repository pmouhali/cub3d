#include "header.h"

char	*set_map_line(char *line, int current_map_w, int current_map_h)
{
	int i;
	char *map_line;

	i = 0;
	while (ft_index(line, "012NSEW") > -1)
		i++;
	if (i != w)
		// pas de la même longueur que la premiere ligne ou charactere inconnu
	// strndup jusqu'a i
	return (map_line);
}
