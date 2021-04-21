/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"
#include "engine.h"

int	check_wall_hit(t_coords *c, t_params *p, double x_offset, double y_offset)
{
	int	dof;

	dof = 0;
	while (dof++ < 100)
	{
		if (c->y / C_S >= p->map.map_h)
			c->y -= 0.0000005;
		if (c->x >= 0
			&& c->x <= p->map.map_w * C_S
			&& c->y >= 0
			&& c->y <= p->map.map_h * C_S)
		{
			if (is_sprite_spec(p->map.map[(int)c->y / C_S][(int)c->x / C_S]))
				set_sprite_visible(&p->s_data,
					(int)c->x / C_S, (int)c->y / C_S);
			if (p->map.map[(int)c->y / C_S][(int)c->x / C_S] == '1')
				return (1);
		}
		c->x += x_offset;
		c->y += y_offset;
	}
	return (0);
}

int	check_hori_lines(t_params *p, double ra, t_coords *c)
{
	double	x_offset;
	double	y_offset;
	double	inv_tan;

	inv_tan = -1 / tan(ra);
	if (ra == 0 || ra == PI)
		return (0);
	if (ra > PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S - 0.0005;
		c->x = (p->player.pos_y - c->y) * inv_tan + p->player.pos_x;
		y_offset = -C_S ;
		x_offset = -y_offset * inv_tan;
	}
	if (ra < PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S + C_S;
		c->x = (p->player.pos_y - c->y) * inv_tan + p->player.pos_x;
		y_offset = C_S ;
		x_offset = -y_offset * inv_tan;
	}
	if (check_wall_hit(c, p, x_offset, y_offset))
		return (1);
	return (0);
}

int	check_vert_lines(t_params *p, double ra, t_coords *c)
{
	double	x_offset;
	double	y_offset;
	double	neg_tan;

	neg_tan = -tan(ra);
	if (ra == PI / 2 || ra == 3 * PI / 2)
		return (0);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S - 0.0005;
		c->y = (p->player.pos_x - c->x) * neg_tan + p->player.pos_y - 0.0000005;
		x_offset = -C_S;
		y_offset = -x_offset * neg_tan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S + C_S;
		c->y = (p->player.pos_x - c->x) * neg_tan + p->player.pos_y - 0.0000005;
		x_offset = C_S;
		y_offset = -x_offset * neg_tan;
	}
	if (check_wall_hit(c, p, x_offset, y_offset))
		return (1);
	return (0);
}
