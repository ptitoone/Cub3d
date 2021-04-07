/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:39 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/24 10:40:17 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int draw_cell(int w, int h, t_params *p)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = p->win_w / p->map.map_w;
	y = p->win_h / p->map.map_h;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (j == 0 || j == x || i == 0 || i == y)
				put_pixel(&p->img, ((w * x) + j++), ((h * y) + i), 0x00FFFFFF);
			else
				put_pixel(&p->img, ((w * x) + j++), ((h * y) + i), 0150150150);
		}
		j = 0;
		i++;
	}
	return (0);
}

static int draw_cell2(int w, int h, t_params *p)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = floor(p->win_w / p->map.map_w);
	y = floor(p->win_h / p->map.map_h);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (j == 0 || j == x || i == 0 || i == y)
				put_pixel(&p->img, ((w * x) + j++), ((h * y) + i), 0x00FFFFFF);
			else
				put_pixel(&p->img, ((w * x) + j++), ((h * y) + i), 0200200200);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	draw_map(t_params *p)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (h < p->map.map_h)
	{
		while (w < p->map.map_w)
		{
			if (p->map.map[h][w] == '1')
				draw_cell(w, h, p);
			else
				draw_cell2(w, h, p);
			w++;
		}
		w = 0;
		h++;
	}
	return (0);
}
