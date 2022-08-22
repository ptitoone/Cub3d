#include "../incls/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = n;
	while (n-- > 0)
		*(unsigned char *)str++ = c;
	return (str - i);
}
