/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:42 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_player(int x, int y, t_params *p)
{
	my_mlx_pixel_put(&p->img, x, y, 0x00D66100);
	my_mlx_pixel_put(&p->img, x - 1, y - 1, 0x00D66100);
	my_mlx_pixel_put(&p->img, x - 1, y + 1, 0x00D66100);
	my_mlx_pixel_put(&p->img, x + 1, y - 1, 0x00D66100);
	my_mlx_pixel_put(&p->img, x + 1, y + 1, 0x00D66100);
	ft_draw_player_ori(p);
}
