/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:17:41 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "errors.h"
#include "libft.h"

static void	new_sprite(t_sprite *sprite, int x, int y, int tex)
{
		sprite->x = x /** (double)C_S*/;
		sprite->y = y /** (double)C_S*/;
		sprite->dist = 0.0;
		sprite->tex = tex;
}

static int	count_sprites(t_map *map)
{
	int count;
	int	x;
	int y;

	count = 0;
	y = -1;
	while (++y < map->map_h)
	{
		x = -1;
		while (++x < map->map_w)
		{
			if (map->map[y][x] == '2')
				count++;
		}
	}
	return (count);
}

void	init_sprites(t_params *p)
{
	int 	x;
	int 	y;
	int		i;

	y = -1;
	i = 0;
	p->s_data.count = count_sprites(&p->map);
	p->s_data.sprites = (t_sprite *)malloc(p->s_data.count * sizeof(t_sprite));
	while (++y < p->map.map_h)
	{
		x = -1;
		while (++x < p->map.map_w)
		{
			if (p->map.map[y][x] == '2')
 				 new_sprite(&p->s_data.sprites[i++], x, y, 2);
		}
	}
}