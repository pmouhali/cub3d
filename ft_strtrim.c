#include "header.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_index(set, s1[i]) != -1)
		i++;
	j = i;
	while (s1[j] != '\0')
		j++;
	if ((j = j > 0 ? j - 1 : 0) > 0)
		while (j > 0 && ft_index(set, s1[j]) != -1)
				j--;
	new = ft_substr(s1, i, (j - i) + 1);
	return (new);
}
