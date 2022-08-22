#include "../incls/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == 0)
	{
		while (*s != 0)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != 0)
		{
			if (*s == ch)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}
