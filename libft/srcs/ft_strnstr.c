#include "libft.h"

char	*ft_strnstr(const char *chain, const char *key, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (key[i] == 0)
		return ((char *)chain);
	while (chain[i] != 0 && i != n)
	{
		if (key[j] == 0)
			return ((char *)chain);
		while (chain[i + j] == key[j] && (i + j) != n)
		{
			j++;
			if (key[j] == '\0')
				return ((char *)&chain[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
