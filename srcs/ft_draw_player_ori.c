/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_ori.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:12 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 12:28:56 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_plot_line (int x0, int y0, int x1, int y1, t_params *p)
{
	int dx;
	int dy;
	int sx;
	int sy;
  	int err;
	int e2;

	dx =  abs(x1 - x0);
	dy = -abs(y1 - y0);
  	err = dx + dy; 
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	while (1)
	{  
		my_mlx_pixel_put(&p->img, x0, y0, 0x00FF0000);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{ 
			err += dy;
			x0 += sx; 
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_draw_player_ori(t_params *p)
{
	int x1 = cos(p->player.orient) * (C_H / 2);
	int y1 = sin(p->player.orient) * (C_H / 2);

	ft_plot_line(p->player.pos_x, p->player.pos_y, p->player.pos_x + x1, p->player.pos_y + y1, p);
}