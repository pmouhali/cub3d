#include "header.h"

void	ft_puterror(char const *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(2, "Error\n", 6);
	write(2, s, i);
}
