#include "../incls/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	p = malloc(nitems * size);
	if (p != NULL)
		ft_bzero(p, nitems * size);
	return (p);
}
