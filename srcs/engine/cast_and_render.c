/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_and_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "engine.h"
#include "utils.h"
#include "draw.h"

static void	init_coords(t_coords *h, t_coords *v, t_params *p)
{
	h->x = p->player.pos_x;
	h->y = p->player.pos_y;
	v->x = p->player.pos_x;
	v->y = p->player.pos_y;
}

static void	handle_radian_overflow(double *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
}

int	cast_and_render(t_params *p)
{
	int			i;
	double		ra;
	t_coords	h;
	t_coords	v;

	init_coords(&h, &v, p);
	i = -1;
	ra = p->player.orient - (30 * PI / 180);
	treat_sprites(p);
	while (i++ < p->win_w - 1)
	{
		handle_radian_overflow(&ra);
		check_lines(p, ra, &h, &v);
		if (calc_dist(h.x, p->player.pos_x, h.y, p->player.pos_y)
			<= calc_dist(v.x, p->player.pos_x, v.y, p->player.pos_y))
			draw_line_h(i, ra, &h, p);
		else
			draw_line_v(i, ra, &v, p);
		ra += ((60 * PI / 180) / p->win_w);
	}
	draw_sprites(p);
	mlx_put_image_to_window(p->mlx, p->win, p->frame.img, 0, 0);
	return (0);
}
