#include "errors.h"
#include "cub.h"
#include "parse.h"
#include "utils.h"
#include "get_next_line.h"

static int	is_map_line(char const *l, t_params *p)
{
	int	i;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] == 0)
		return (0);
	while (l[i] == ' '
		|| l[i] == '0'
		|| l[i] == '1'
		|| is_sprite_spec(l[i])
		|| is_pos(l[i]))
		i++;
	if (l[i] == 0)
	{
		if (i >= p->map.map_w)
			p->map.map_w = i;
		p->map.map_h++;
		return (1);
	}
	return (0);
}

int	parse_map_size(int map_fd, t_params *p)
{
	char	*line;

	line = NULL;
	while (get_next_line(map_fd, &line) == 1 && !(is_map_line(line, p)))
		free_line(&line);
	if (p->map.map_h == 1)
	{
		free_line(&line);
		while (get_next_line(map_fd, &line) == 1)
		{
			if (!(is_map_line(line, p)))
			{
				free_line(&line);
				return (1);
			}
			free_line(&line);
		}
		is_map_line(line, p);
		free_line(&line);
		return (1);
	}
	return (throw_error(ERR_MAP_NF));
}
