/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptito <akotzky@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:39:41 by ptito             #+#    #+#             */
/*   Updated: 2021/03/11 14:26:25 by ptito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/cub.h"

static int ft_draw_cell(int w, int h, t_params *p)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = p->win_w / p->map.map_w;
	x = floor(x);
	y = p->win_h / p->map.map_h;
	y = floor(y);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), 0x00595959);
			else
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), 0150150150);
		}
		j = 0;
		i++;
	}
	return (0);
}

static int ft_draw_cell2(int w, int h, t_params *p)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = p->win_w / p->map.map_w;
	x = floor(x);
	y = p->win_h / p->map.map_h;
	y = floor(y);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), 0x00595959);
			else
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), 0200200200);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_draw_map(t_params *p)
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
				ft_draw_cell(w, h, p);
			else
				ft_draw_cell2(w, h, p);
			w++;
		}
		w = 0;
		h++;
	}
}
