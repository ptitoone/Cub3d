#include "../incls/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				d;
	int				e;

	if ((n >= 0) && (n <= INT_MAX))
	{
		d = (48 + (n % 10));
		e = (n / 10);
		if (e > 0)
			ft_putnbr_fd(e, fd);
		ft_putchar_fd(d, fd);
	}
	if ((n < 0) && (n >= INT_MIN))
	{
		ft_putchar_fd('-', fd);
		nb = -n;
		d = (48 + (nb % 10));
		e = (nb / 10);
		if (e > 0)
			ft_putnbr_fd(e, fd);
		ft_putchar_fd(d, fd);
	}
}
