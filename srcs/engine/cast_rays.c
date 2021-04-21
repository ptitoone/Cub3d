/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "engine.h"

static void	init_coords(t_coords *h, t_coords *v, t_params *p)
{
	h->x = p->player.pos_x;
	h->y = p->player.pos_y;
	v->x = p->player.pos_x;
	v->y = p->player.pos_y;
}

int	render_frame(t_params *p)
{
	int			i;
	double		ra;
	t_coords	h;
	t_coords	v;

	init_coords(&h, &v, p);
	i = -1;
	ra = p->player.orient - (30 * PI / 180);
	calc_sprite_dist(p);
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
			draw_line_h(i, ra, &h, p);
		else
			draw_line_v(i, ra, &v, p);
		ra += ((60 * PI / 180) / p->win_w);
	}
	sort_sprites(p->s_data.sprites, p->s_data.count);
	calc_sprite_screen_x_pos(p);
	draw_sprites(p);
	draw_hands(p);
	mlx_do_sync(p->mlx);
	mlx_put_image_to_window(p->mlx, p->win2, p->imgv.img, 0, 0);
	return (0);
}
