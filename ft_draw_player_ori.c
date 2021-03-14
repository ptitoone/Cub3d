/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_ori.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptito <akotzky@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:01:06 by ptito             #+#    #+#             */
/*   Updated: 2021/03/14 19:07:45 by ptito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/cub.h"

void	ft_draw_player_ori(t_params *p)
{
	int	i;
	int	x;
	int	y;
	
	int a = 0;
	int b = 0;

	i = -1;
	x = p->player.pos_x;
	y = p->player.pos_y;

	while (i++ < 5)
	{
		while (b++ <= 4)
		{
			while (a++ <= 1)
				my_mlx_pixel_put(&p->img, x, y--, 0x00FF0000);
			a = 0;
			x++;
		}
		b = 0;
	}
}
