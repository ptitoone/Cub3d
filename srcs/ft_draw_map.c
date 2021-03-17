/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:39 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 13:22:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int ft_draw_cell(int w, int h, t_params *p)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = C_H;
	y = x;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (j == 0 || j == x || i == 0 || i == y)
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), /*0x00FFFFFF*/0150150150);
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

	x = C_H;
	y = x;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (j == 0 || j == x || i == 0 || i == y)
				my_mlx_pixel_put(&p->img, ((w * x) + j++), ((h * y) + i), /*0x00FFFFFF*/0200200200);
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
	return (0);
}
