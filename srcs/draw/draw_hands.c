/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void draw_hands(t_params *p)
{
	int x = 400 - 175;
	int y = 800 - 350;
	int i = 0;
	int j = 0;
	double tex_x = 0;
	double tex_y = 0;
	int color;
	double step = 128.0/350.0;

	while (j < 350)
	{
		while (i < 350)
		{
			color = (int)get_pixel_color(&p->tex.hands,(int)tex_x, (int)tex_y);
			if (color != 0)
				put_pixel(&p->imgv, x, y, color);
			tex_x+=step;
			i++;
			x++;
		}
		x = 400 - 175;
		i = 0;
		j++;
		tex_x=0;
		tex_y+=step;
		y++;
	}
}
