#include "cub.h"
#include "utils.h"

void	set_sprite_visible(t_sprite_data *s, int x, int y)
{
	int	i;

	i = -1;
	while (i++ < s->count)
	{
		if (x == (int)(s->sprites[i].x / C_S)
			&& y == (int)(s->sprites[i].y / C_S))
		{
			s->sprites[i].visible = 1;
			break ;
		}
	}
}

void	calc_sprite_dist(t_params *p)
{
	int		i;

	i = 0;
	while (i < p->s_data.count)
	{
		p->s_data.sprites[i].dist
			= calc_dist(p->player.pos_x, p->s_data.sprites[i].x,
				p->player.pos_y, p->s_data.sprites[i].y);
		p->s_data.sprites[i].visible = 0;
		i++;
	}
}

void	sort_sprites(t_sprite *sprites, int count)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (count > 1)
	{
		while (i < count - 1)
		{
			if (sprites[i].dist < sprites[i + 1].dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		count--;
	}
}

void	calc_sprite_screen_x_pos(t_params *p)
{
	double	h_x;
	double	h_y;
	double	aTan;
	double	angle;
	int		i;

	i = 0;
	while (i < p->s_data.count)
	{
		h_x = p->s_data.sprites[i].x - p->player.pos_x;
		h_y = p->s_data.sprites[i].y - p->player.pos_y;
		aTan = atan2(-h_y, h_x);
		aTan *= (180 / PI);
		aTan = -aTan;
		if (aTan < 0)
			aTan += 360;
		angle = (p->player.orient * 180 / PI) + 30 - aTan;
		if ((angle > 360))
			angle -= 360;
		if ((angle < 0))
			angle += 360;
		p->s_data.sprites[i].scrn_x = (int)(angle * (double)p->win_w / 60.0);
		p->s_data.sprites[i].scrn_x = p->win_w - p->s_data.sprites[i].scrn_x;
		i++;
	}
}

void	treat_sprites(t_params *p)
{
	calc_sprite_dist(p);
	sort_sprites(p->s_data.sprites, p->s_data.count);
	calc_sprite_screen_x_pos(p);
}
