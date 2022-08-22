#include "../incls/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst - i);
}
