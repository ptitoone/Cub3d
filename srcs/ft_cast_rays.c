/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/17 16:24:32 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_find_wall(t_params *p)
{
	float x1;
	float y1;
	float xo;
	float yo;
	int i, z, b, j;
	float ra = p->player.orient - (30 * PI / 180);

	i = -1;
	j = 5;
	while(i++ < 24)
	{
		xo = p->player.pos_x;
		yo = p->player.pos_y;
		x1 = cos(ra) / 64;
		y1 = sin(ra) / 64;
		while (1)
		{
			xo += x1;
			yo += y1;
			z =(int)floor(xo);
			b =(int)floor(yo);
			if (p->map.map[b/64][z/64] == '1')
				break ;
		}
 		ft_plot_line(p->player.pos_x, p->player.pos_y, z, b, 0x0000FF00, p);
		i++;
		ra += (j * PI / 180);
	}
	return (0);
}
