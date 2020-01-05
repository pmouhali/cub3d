#include "header.h"

int		is_file_extension(const char *path, const char *extension)
{
	int i;
	int j;

	if (path[0] == 0 || extension[0] == 0)
		return (0);
	i = ft_strlen(path) - 1;
	j = ft_strlen(extension) - 1;
	while (i >= 0 && j >= 0 && path[i] == extension[j])
	{
		i--;
		j--;
	}
	if (j == -1)
		return (1);
	return (0);
}
