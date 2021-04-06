/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:59:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:03 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_calculate_data(t_params *p, double x, double y, double i, t_draw_l *data)
{
	data->dist = sqrt(pow(p->player.pos_x - x, 2) + pow(p->player.pos_y - y, 2));
	data->dist = data->dist * cos(p->player.orient - data->ra);
	data->wall_h = (int)floor(((p->map.c_s  * p->win_h) / data->dist) / p->ratio);
	data->ratio_y = 64.0 / (double)(data->wall_h * 2);
	data->tex_x = (int)i % p->map.c_s;
	if(data->tex_x == 64)
		data->tex_x -= 1;
	data->tex_y = 0;
	if (data->wall_h * 2 > p->win_h)
	{
		data->tex_y = (((data->wall_h * 2) - p->win_h) / 2) * data->ratio_y;
		data->wall_h = p->win_h / 2;
	}
}

void	ft_draw_line_h(int rc, double ra, double x, double y, t_params *p, int color)
{
	int i;
	int j;
	t_draw_l data;

	i = 0;
	j = 0;
	data.ra = ra;
	ft_calculate_data(p, x, y, x, &data);
	while (i++ < (p->win_h / 2) - data.wall_h)
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x002E4172);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > 0 && ra < PI)
			ft_draw_tex_col(&p->tex.no, data.tex_x, (int)data.tex_y, rc, j++, &p->imgv);
		else if (ra > PI && ra < 2 * PI)
			ft_draw_tex_col(&p->tex.so, data.tex_x, (int)data.tex_y, rc, j++, &p->imgv);
		data.tex_y += data.ratio_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00353D4E);
}

void	ft_draw_line_v(int rc, double ra, double x, double y, t_params *p, int color)
{
	int i;
	int j;
	t_draw_l data;

	i = 0;
	j = 0;
	data.ra = ra;
	ft_calculate_data(p, x, y, y, &data);
	while (i++ < (p->win_h / 2) - data.wall_h)
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x002E4172);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > PI / 2 && ra < 3 * PI / 2)
			ft_draw_tex_col(&p->tex.we, data.tex_x, (int)data.tex_y, rc, j++, &p->imgv);
		else if (ra > 3 * PI / 2 || ra < PI / 2)
			ft_draw_tex_col(&p->tex.ea, data.tex_x, (int)data.tex_y, rc, j++, &p->imgv);
		data.tex_y += data.ratio_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00353D4E);
}
