#include "../incls/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*d;
	char			*s;

	i = len;
	d = NULL;
	s = NULL;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		while (len-- > 0)
			*(char *)dst++ = *(char *)src++;
	else
	{
		d = (char *)dst + (len - 1);
		s = (char *)src + (len - 1);
		while (len-- > 0)
			*(char *)d-- = *(char *)s--;
		return (dst);
	}
	return (dst - i);
}
