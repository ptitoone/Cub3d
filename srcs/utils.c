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

void	calculate_sprite_dist(t_params *p)
{
	double 	x;
	double 	y;
	int		i;

	i = 0;
	while (i < p->s_data.count)
	{
		x = pow((p->player.pos_x - p->s_data.sprites[i].x), 2);
		y = pow((p->player.pos_y - p->s_data.sprites[i].x), 2);
		p->s_data.sprites[i].dist = x + y;
		i++;
	}
}

void sort_sprites(t_sprite *sprites, int count)
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