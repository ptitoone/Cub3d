#include "../incls/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	ch;

	ch = c;
	write(fd, &ch, 1);
}
