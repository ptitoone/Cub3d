#include "libft.h"

char	*ft_strstr(const char *chain, const char *key)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (key[i] == 0)
		return ((char *)chain);
	while (chain[i] != 0)
	{
		while (chain[i + j] == key[j])
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
