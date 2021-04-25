/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:17:41 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"
#include "errors.h"

static int	check_walls_x(t_params *p, int x, int y)
{
	int	hori;

	hori = x;
	while (hori < p->map.map_w)
	{
		if (p->map.map[y][hori++] == '1')
		{
			hori = x;
			while (hori >= 0)
			{
				if (p->map.map[y][hori--] == '1')
					return (1);
			}
			break ;
		}
	}
	return (0);
}

static int	check_walls_y(t_params *p, int x, int y)
{
	int	vert;

	vert = y;
	while (vert < p->map.map_h)
	{
		if (p->map.map[vert++][x] == '1')
		{
			vert = y;
			while (vert >= 0)
			{
				if (p->map.map[vert--][x] == '1')
					return (1);
			}
			break ;
		}
	}
	return (0);
}

int	check_map_validity(t_params *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < p->map.map_h)
	{
		while (x < p->map.map_w)
		{
			if (p->map.map[y][x] == '0'
				|| is_sprite_spec(p->map.map[y][x])
				|| is_pos(p->map.map[y][x]))
			{
				if (!check_walls_x(p, x, y))
					return (throw_error(ERR_MAP_NOT_CLOSED));
				if (!check_walls_y(p, x, y))
					return (throw_error(ERR_MAP_NOT_CLOSED));
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
