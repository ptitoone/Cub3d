#include "cub.h"
#include "libft.h"
#include "errors.h"

static void	init_new_sprite(t_sprite *sprite, int x, int y, int tex)
{
	sprite->x = (x * C_S) + (double)C_S / 2;
	sprite->y = (y * C_S) + (double)C_S / 2;
	sprite->scrn_x = 0;
	sprite->dist = 0.0;
	sprite->visible = 0;
	sprite->tex = tex;
}

static int	count_sprites(t_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = -1;
	while (++y < map->map_h)
	{
		x = -1;
		while (++x < map->map_w)
			if (map->map[y][x] == '2')
				count++;
	}
	return (count);
}

int	init_sprites(t_params *p)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = 0;
	p->s_data.count = count_sprites(&p->map);
	p->s_data.sprites = (t_sprite *)malloc(p->s_data.count * sizeof(t_sprite));
	if (p->s_data.sprites == NULL)
		return (throw_error(ERR_MALLOC_FAIL));
	while (++y < p->map.map_h)
	{
		x = -1;
		while (++x < p->map.map_w)
			if (p->map.map[y][x] == '2')
				init_new_sprite(&p->s_data.sprites[i++], x, y, S1);
	}
	return (1);
}
