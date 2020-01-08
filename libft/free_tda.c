#include "libft.h"

void    free_tda(void **two_dimensional_array, int first_dimension_length)
{
	int i;

	i = 0;
	while (i < first_dimension_length)
	{
		free(two_dimensional_array[i]);
		i++;
	}
	free((void*)two_dimensional_array);
	two_dimensional_array = NULL;
}
