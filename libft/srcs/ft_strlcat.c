#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	srclen;
	unsigned int	destlen;
	unsigned int	i;
	unsigned int	j;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	i = destlen;
	j = 0;
	if (dstsize > 0)
	{
		while (src[j] != 0 && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (dstsize < destlen)
		return (dstsize + srclen);
	return (srclen + destlen);
}
