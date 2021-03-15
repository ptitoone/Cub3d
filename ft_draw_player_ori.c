/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_ori.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptito <akotzky@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:01:06 by ptito             #+#    #+#             */
/*   Updated: 2021/03/15 10:25:34 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/cub.h"

static void	plot_line (int x0, int y0, int x1, int y1, t_params *p)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  for (;;){  /* loop */
    my_mlx_pixel_put(&p->img, x0, y0, 0x00FF0000);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

void	ft_draw_player_ori(t_params *p)
{
	int x1 = cos(p->player.orient) * (C_H / 2);
	int y1 = sin(p->player.orient) * (C_H / 2);

	plot_line(p->player.pos_x, p->player.pos_y, p->player.pos_x + x1, p->player.pos_y + y1, p);
}
