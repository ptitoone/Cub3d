#include "cub.h"
#include "controls.h"
#include "utils.h"

int	destroy(void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	free_params(p);
	exit(EXIT_SUCCESS);
}
