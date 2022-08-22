#include "../incls/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*(unsigned char *)src == ch)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return ((void *)dst + 1);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (NULL);
}
