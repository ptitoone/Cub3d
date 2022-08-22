#include "../incls/libft.h"

char	*ft_strdup(const char *str)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (sdup == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		sdup[i] = str[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
