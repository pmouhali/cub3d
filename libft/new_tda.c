#include "libft.h"

void	**new_tda(int size, int height, int width)
{
	void	**two_dimensional_array;
	int x;

	if (!(two_dimensional_array = (void**)malloc(sizeof(void*) * height)))
		return (NULL);
	x = -1;
	while (++x < height)
	{
		if (!(two_dimensional_array[x] = malloc(size * width)))
		{
			free_tda(two_dimensional_array, x);
			return (NULL);
		}
		ft_bzero(two_dimensional_array[x], size * width);
	}
	return (two_dimensional_array);
}
