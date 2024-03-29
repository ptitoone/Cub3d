#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s) < len)
		str = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
