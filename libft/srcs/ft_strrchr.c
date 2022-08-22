#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = ft_strlen(s);
	ch = c;
	s += len;
	while (len >= 0)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}
