#include "cub.h"
#include "draw.h"

static void	calc_data(t_params *p, t_coords *c, double i, t_draw_l *data)
{
	if (i == c->x)
	{
		c->x--;
		c->y--;
	}
	data->dist = sqrt(pow(p->player.pos_x - c->x, 2)
			+ pow(p->player.pos_y - c->y, 2));
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

void	draw_line_h(int rc, double ra, t_coords *c, t_params *p)
{
	int			i;
	int			j;
	t_draw_l	data;

	i = 0;
	j = 0;
	data.ra = ra;
	calc_data(p, c, c->x, &data);
	p->s_data.col_dist[rc] = data.dist / cos(p->player.orient - data.ra);
	while (i++ < (p->win_h / 2) - data.wall_h)
		put_pixel(&p->frame, rc, j++, p->tex.c_color);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > 0 && ra < PI)
			put_pixel(&p->frame, rc, j++,
				(int)p->tex.type[NO].clr[(int)data.tex_y][(int)data.tex_x]);
		else if (ra > PI && ra < 2 * PI)
			put_pixel(&p->frame, rc, j++,
				(int)p->tex.type[SO].clr[(int)data.tex_y][(int)data.tex_x]);
		data.tex_y += data.step_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		put_pixel(&p->frame, rc, j++, p->tex.f_color);
}

void	draw_line_v(int rc, double ra, t_coords *c, t_params *p)
{
	int			i;
	int			j;
	t_draw_l	data;

	i = 0;
	j = 0;
	data.ra = ra;
	calc_data(p, c, c->y, &data);
	p->s_data.col_dist[rc] = data.dist / cos(p->player.orient - data.ra);
	while (i++ < (p->win_h / 2) - data.wall_h)
		put_pixel(&p->frame, rc, j++, p->tex.c_color);
	i = 0;
	while (i++ < data.wall_h * 2)
	{
		if (ra > PI / 2 && ra < 3 * PI / 2)
			put_pixel(&p->frame, rc, j++,
				(int)p->tex.type[WE].clr[(int)data.tex_y][(int)data.tex_x]);
		else if (ra > 3 * PI / 2 || ra < PI / 2)
			put_pixel(&p->frame, rc, j++,
				(int)p->tex.type[EA].clr[(int)data.tex_y][(int)data.tex_x]);
		data.tex_y += data.step_y;
	}
	i = 0;
	while (i++ < ((p->win_h / 2) - data.wall_h))
		put_pixel(&p->frame, rc, j++, p->tex.f_color);
}
