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
	int x1;
	int y1;
	int i;

	i = 1;
	x1 = cos(p->player.orient) + p->player.pos_x;
	y1 = sin(p->player.orient) + p->player.pos_y;
	while (1)
	{
		if (x1 % 64 == 0 || y1 % 64 == 0)
			break ;
		x1 = (cos(p->player.orient) * i) + p->player.pos_x;
		y1 = (sin(p->player.orient) * i) + p->player.pos_y;
		i++;
	}
	ft_plot_line(p->player.pos_x, p->player.pos_y, x1, y1, 0x0000FF00, p);
	return (0);
}
