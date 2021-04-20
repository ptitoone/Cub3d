/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c  		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:59:03 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:03 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	calculate_data(t_params *p, double x, double y, double i, t_draw_l *data)
{
	data->dist = sqrt(pow(p->player.pos_x - x, 2)
			+ pow(p->player.pos_y - y, 2));
	data->dist = data->dist * cos(p->player.orient - data->ra);
	data->wall_h = (int)floor(((C_S * p->win_h) / data->dist));
	data->step_y = 64.0 / (double)(data->wall_h * 2);
	data->tex_x = (int)i % C_S;
	if (data->tex_x == 64)
		data->tex_x -= 1;
	data->tex_y = 0;
	if (data->wall_h * 2 > p->win_h)
	{
		data->tex_y = (((data->wall_h * 2) - (double)p->win_h) / 2)
			* data->step_y;
		data->wall_h = p->win_h / 2;
	}
}

void	draw_line_h(int rc, double ra, double x, double y, t_params *p)
{
	int			i;
	int			j;
	t_draw_l	data;

	i = 0;
	j = 0;
	data.ra = ra;
	calculate_data(p, x, y, x, &data);
	p->s_data.col_dist[rc] = data.dist / cos(p->player.orient - data.ra);
	while (i++ < (p->win_h / 2) - data.wall_h)
		put_pixel(&p->imgv, rc, j++, p->tex.c_color);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > 0 && ra < PI)
			put_pixel(&p->imgv, rc, j++,
				(int)p->tex.t_no[(int)data.tex_y][(int)data.tex_x]);
		else if (ra > PI && ra < 2 * PI)
			put_pixel(&p->imgv, rc, j++,
				(int)p->tex.t_so[(int)data.tex_y][(int)data.tex_x]);
		data.tex_y += data.step_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		put_pixel(&p->imgv, rc, j++, p->tex.f_color);
}

void	draw_line_v(int rc, double ra, double x, double y, t_params *p)
{
	int			i;
	int			j;
	t_draw_l	data;

	i = 0;
	j = 0;
	data.ra = ra;
	calculate_data(p, x, y, y, &data);
	p->s_data.col_dist[rc] = data.dist / cos(p->player.orient - data.ra);
	while (i++ < (p->win_h / 2) - data.wall_h)
		put_pixel(&p->imgv, rc, j++, p->tex.c_color);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > PI / 2 && ra < 3 * PI / 2)
			put_pixel(&p->imgv, rc, j++,
				(int)p->tex.t_we[(int)data.tex_y][(int)data.tex_x]);
		else if (ra > 3 * PI / 2 || ra < PI / 2)
			put_pixel(&p->imgv, rc, j++,
				(int)p->tex.t_ea[(int)data.tex_y][(int)data.tex_x]);
		data.tex_y += data.step_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		put_pixel(&p->imgv, rc, j++, p->tex.f_color);
}
