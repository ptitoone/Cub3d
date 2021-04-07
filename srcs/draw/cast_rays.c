/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_wall(t_coords *c, t_params *p, double xo, double yo)
{
	int dof;

	dof = 0;
	while (dof++ < 100)
	{
		if (c->x >= 0
			&& c->x <= p->map.map_w * p->map.c_s
			&& c->y >= 0
			&& c->y <= p->map.map_h * p->map.c_s)
			if (p->map.map[(int)c->y/p->map.c_s][(int)c->x/p->map.c_s] == '1')
				return (1);
		c->x+=xo;
		c->y+=yo;
	}
	return (0);
}

static int check_hori_lines(t_params *p, double ra, t_coords *c)
{
	double 	xo;
	double 	yo;
	double 	itan;

	itan  = -1 / tan(ra);
	if (ra == 0 || ra == PI)
		return (0);
	if (ra > PI)
	{
		c->y = floor(p->player.pos_y / p->map.c_s ) * (p->map.c_s ) - 0.0005;
		c->x = (p->player.pos_y - c->y) * itan + p->player.pos_x ;
		yo = -p->map.c_s ;
		xo = -yo * itan;
	}
	if (ra < PI)
	{
		c->y = floor(p->player.pos_y / p->map.c_s ) * (p->map.c_s ) + p->map.c_s;
		c->x = (p->player.pos_y - c->y) * itan + p->player.pos_x ;
		yo = p->map.c_s ;
		xo = -yo * itan;
	}
	if (check_wall(c, p, xo, yo))
		return (1);
	return (0);
}

static int	check_vert_lines(t_params *p, double ra, t_coords *c)
{
	double 	xo;
	double 	yo;
	double 	ntan;

	ntan = -tan(ra);
	if (ra == PI / 2 || ra == 3 * PI / 2)
		return (0);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / p->map.c_s) * (p->map.c_s) - 0.0005;
		c->y = (p->player.pos_x - c->x) * ntan + p->player.pos_y ;
		xo = -p->map.c_s;
		yo = -xo * ntan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / p->map.c_s) * (p->map.c_s) + p->map.c_s;
		c->y = (p->player.pos_x - c->x) * ntan + p->player.pos_y ;
		xo = p->map.c_s;
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

int find_wall(t_params *p)
{
	int 	i;
	double	ra;
	t_coords h;
	t_coords v;

	init_coords(&h, &v, p);
	i = -1;
	ra = p->player.orient - (30 * PI / 180);
	while(i++ < p->win_w - 1)
	{
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		check_hori_lines(p, ra, &h);
		check_vert_lines(p, ra, &v);
		if (sqrt(pow(h.x - p->player.pos_x, 2) + pow(h.y - p->player.pos_y, 2))
			<= sqrt(pow(v.x - p->player.pos_x, 2) + pow(v.y - p->player.pos_y, 2)))
			draw_line_h(i, ra, h.x - 1, h.y - 1, p, 0x00F17600);
		else
			draw_line_v(i, ra, v.x, v.y, p, 0x00954900);
		ra += ((60 * PI / 180) / p->win_w);
	}
//	mlx_sync(1, p->imgv.img);
	mlx_put_image_to_window(p->mlx, p->win2, p->imgv.img, 0, 0);
//	mlx_sync(3, p->win2);
	return (0);
}

