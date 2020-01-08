#include "libft.h"

char	*ft_strctrim(const char *s, int c)
{
	int i;
	int j;
	char *new;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c)
			j++;
	if (!(new = (char*)malloc(sizeof(char) * (j + 1))))
		return (new);
	new[j] = 0;
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != c)
			new[++j] = s[i];	
	}
	return (new);
}
