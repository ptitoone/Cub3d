#include "cub.h"
#include "errors.h"
#include "utils.h"

int	throw_error(char *error)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
