#include "libft.h"

void	ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	if (str)
	{
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			j--;
			i++;
		}
	}
}
