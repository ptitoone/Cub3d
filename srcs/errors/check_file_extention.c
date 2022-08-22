#include "errors.h"

int	check_file_extention(const char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[--i] == 'b')
		if (file_name[--i] == 'u')
			if (file_name[--i] == 'c')
				if (file_name[--i] == '.')
					return (1);
	return (throw_error(ERR_FILE_EXT_INV));
}
