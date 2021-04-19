/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include "cub.h"

static void set_sprite_visible(t_sprite_data *s, int x, int y)
{
	int i;

	i = -1;
	while (i++ < s->count)
	{
		if (x == (int)(s->sprites[i].x / C_S) && y == (int)(s->sprites[i].y / C_S))
		{
			s->sprites[i].visible = 1;
			break;
		}
	}
}

static int	check_wall(t_coords *c, t_params *p, double xo, double yo)
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
			if (p->map.map[(int)c->y / C_S][(int)c->x / C_S] == '2')
				set_sprite_visible(&p->s_data, (int)c->x / C_S, (int)c->y / C_S);
			if (p->map.map[(int)c->y / C_S][(int)c->x / C_S] == '1')
				return (1);
		}
		c->x += xo;
		c->y += yo;
	}
	return (0);
}

static int	check_hori_lines(t_params *p, double ra, t_coords *c)
{
	double	xo;
	double	yo;
	double	itan;

	itan = -1 / tan(ra);
	if (ra == 0 || ra == PI)
		return (0);
	if (ra > PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S - 0.0005;
		c->x = (p->player.pos_y - c->y) * itan + p->player.pos_x;
		yo = -C_S ;
		xo = -yo * itan;
	}
	if (ra < PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S + C_S;
		c->x = (p->player.pos_y - c->y) * itan + p->player.pos_x;
		yo = C_S ;
		xo = -yo * itan;
	}
	if (check_wall(c, p, xo, yo))
		return (1);
	return (0);
}

static int	check_vert_lines(t_params *p, double ra, t_coords *c)
{
	double	xo;
	double	yo;
	double	ntan;

	ntan = -tan(ra);
	if (ra == PI / 2 || ra == 3 * PI / 2)
		return (0);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S - 0.0005;
		c->y = (p->player.pos_x - c->x) * ntan + p->player.pos_y - 0.00000005;
		xo = -C_S;
		yo = -xo * ntan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S + C_S;
		c->y = (p->player.pos_x - c->x) * ntan + p->player.pos_y - 0.00000005;
		xo = C_S;
		yo = -xo * ntan;
	}
	if (check_wall(c, p, xo, yo))
		return (1);
	return (0);
}

static void	init_coords(t_coords *h, t_coords *v, t_params *p)
{
	h->x = p->player.pos_x;
	h->y = p->player.pos_y;
	v->x = p->player.pos_x;
	v->y = p->player.pos_y;
}

int	find_wall(t_params *p)
{
	int			i;
	double		ra;
	t_coords	h;
	t_coords	v;

	init_coords(&h, &v, p);
	i = -1;
	ra = p->player.orient - (30 * PI / 180);
	calculate_sprite_dist(p);
	while (i++ < p->win_w - 1)
	{
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		check_hori_lines(p, ra, &h);
		check_vert_lines(p, ra, &v);
		if (sqrt(pow(h.x - p->player.pos_x, 2)
				+ pow(h.y - p->player.pos_y, 2))
			<= sqrt(pow(v.x - p->player.pos_x, 2)
				+ pow(v.y - p->player.pos_y, 2)))
			draw_line_h(i, ra, h.x - 1, h.y - 1, p);
		else
			draw_line_v(i, ra, v.x, v.y, p);
		ra += ((60 * PI / 180) / p->win_w);
	}
	sort_sprites(p->s_data.sprites, p->s_data.count);
	calculate_sprite_screen(p);
	draw_sprites(p);
	mlx_sync(1, p->imgv.img);
	mlx_put_image_to_window(p->mlx, p->win2, p->imgv.img, 0, 0);
	mlx_sync(3, p->win2);
	return (0);
}
