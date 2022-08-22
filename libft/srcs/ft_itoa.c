#include "../incls/libft.h"

static int	ft_countnbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	else if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_buildstr(char *str, int n, size_t len)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		str[len - 1] = '-';
		nb = -n;
	}
	while (nb > 0)
	{
		str[i++] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		i++;
	str[i] = '\0';
	ft_strrev(str);
}

char	*ft_itoa(int n)
{
	int		j;
	char	*str;

	j = ft_countnbr(n);
	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * j + 1);
		if (str == NULL)
			return (NULL);
		ft_buildstr(str, n, j);
	}
	return (str);
}
