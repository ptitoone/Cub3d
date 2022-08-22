#include "../incls/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (n-- > 0)
		if (*(unsigned char *)s++ == ch)
			return ((unsigned char *)s - 1);
	return (NULL);
}
