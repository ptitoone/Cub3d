#include "errors.h"

int	check_args(int argc, const char *argv_1, const char *argv_2, int *save_bmp)
{
	if (argc < 2)
		return (throw_error(ERR_NO_MAP_FILE));
	else if (argc >= 2 && argc <= 3)
	{
		if (argc == 2 && check_file_extention(argv_1))
			return (1);
		else if (argc == 3
			&& check_file_extention(argv_1)
			&& !ft_strncmp(argv_2, "--save-bmp", 10))
		{
			*save_bmp = 1;
			return (1);
		}
		return (throw_error(ERR_INV_ARG));
	}
	return (throw_error(ERR_TOO_MANY_ARGS));
}
