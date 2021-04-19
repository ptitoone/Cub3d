/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_line(char **line)
{
	free(*line);
	*line = NULL;
}

void	calculate_sprite_screen(t_params *p)
{
	double	h_x;
	double	h_y;
	double 	aTan;
	double 	angle;
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
		if (aTan > 360)
			aTan -= 360;
		angle = (p->player.orient * 180 / PI) + 30 - aTan;
		if ((angle > 360))
			angle -= 360;
		if ((angle < 0))
			angle += 360;
		p->s_data.sprites[i].screen_x = (int)(angle * (double)p->win_w / 60.0);
		p->s_data.sprites[i].screen_x = p->win_w - p->s_data.sprites[i].screen_x;
		i++;
	}
}

void	calculate_sprite_dist(t_params *p)
{
	double 	x;
	double 	y;
	int		i;

	i = 0;
	while (i < p->s_data.count)
	{
		x = pow((p->player.pos_x - p->s_data.sprites[i].x), 2);
		y = pow((p->player.pos_y - p->s_data.sprites[i].y), 2);
		p->s_data.sprites[i].dist = sqrt(x + y);
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