char	*ft_strrchr(const char *s, int c)
{
	char *pointer;

	pointer = (void*)0;
	while (*s != '\0')
	{
		if (*s == c)
			pointer = (char*)s;
			s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (pointer);
}
