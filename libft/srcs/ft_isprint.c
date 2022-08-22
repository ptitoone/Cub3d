#include "../incls/libft.h"

int	ft_isprint(int c)
{
	if ((c >= 040) && (c <= 0176))
		return (1);
	return (0);
}
