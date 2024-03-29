#include "cub.h"
#include "draw.h"

static void	calc_sprite_data(t_params *p, int sprite_i, t_draw_s *data)
{
	data->sprite_h
		= (int)floor(((C_S * p->win_h) / p->s_data.sprites[sprite_i].dist));
	data->x = p->s_data.sprites[sprite_i].scrn_x - data->sprite_h;
	data->y = (p->win_h / 2) - data->sprite_h;
	data->step = 64.0 / (double)(data->sprite_h * 2);
	data->tex_x = 0;
	data->tex_y = 0;
	data->i = -1;
	data->j = -1;
	data->texno = p->s_data.sprites[sprite_i].tex;
}

static void	adjust_tex_index_overflow(t_draw_s *d)
{
	if (d->tex_x >= 64)
		d->tex_x = 63;
	if (d->tex_y >= 64)
		d->tex_y = 63;
}

static void	draw_single_sprite(t_params *p, int sprite_i)
{
	t_draw_s	d;

	calc_sprite_data(p, sprite_i, &d);
	while (d.i++ < d.sprite_h * 2)
	{
		while (d.j++ < d.sprite_h * 2)
		{
			adjust_tex_index_overflow(&d);
			if (p->s_data.sprites[sprite_i].visible
				&& (p->s_data.col_dist[d.x] > p->s_data.sprites[sprite_i].dist)
				&& (d.x >= 0 && d.x < p->win_w) && (d.y >= 0 && d.y < p->win_h)
				&& p->tex.type[d.texno].clr[(int)d.tex_x][(int)d.tex_y])
				put_pixel(&p->frame, d.x, d.y,
					(int)p->tex.type[d.texno].clr[(int)d.tex_x][(int)d.tex_y]);
			d.y++;
			d.tex_x += d.step;
		}
		d.tex_x = 0;
		d.tex_y += d.step;
		d.y = (p->win_h / 2) - d.sprite_h;
		d.j = -1;
		d.x++;
	}
}

void	draw_sprites(t_params *p)
{
	int	i;

	i = 0;
	while (i < p->s_data.count)
	{
		draw_single_sprite(p, i);
		i++;
	}
}
