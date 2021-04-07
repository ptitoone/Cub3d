/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:42 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/17 12:09:11 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_player(int x, int y, t_params *p)
{
	put_pixel(&p->img, x, y, 0x00D66100);
	put_pixel(&p->img, x - 1, y - 1, 0x00D66100);
	put_pixel(&p->img, x - 1, y + 1, 0x00D66100);
	put_pixel(&p->img, x + 1, y - 1, 0x00D66100);
	put_pixel(&p->img, x + 1, y + 1, 0x00D66100);
	draw_player_ori(p);
}
