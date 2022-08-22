#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != 0)
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}
