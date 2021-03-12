/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:42 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/12 14:00:02 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/cub.h"

void	ft_draw_player(int x, int y, t_params *p)
{
	my_mlx_pixel_put(&p->img, x, y, 0x00FF7400);
	my_mlx_pixel_put(&p->img, x - 1, y - 1, 0x00FF7400);
	my_mlx_pixel_put(&p->img, x - 1, y + 1, 0x00FF7400);
	my_mlx_pixel_put(&p->img, x + 1, y - 1, 0x00FF7400);
	my_mlx_pixel_put(&p->img, x + 1, y + 1, 0x00FF7400);
}
