/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:58:44 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 13:19:32 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "controls.h"

int	key_w(t_params *p)
{
	int	x_offset;
	int	y_offset;

	x_offset = p->player.pos_x + p->player.del_x * 7;
	y_offset = p->player.pos_y + p->player.del_y * 7;
	if (p->map.map[y_offset / C_S][x_offset / C_S] == '0')
	{
		p->player.pos_x += (2 * p->player.del_x);
		p->player.pos_y += (2 * p->player.del_y);
	}
	return (0);
}

int	key_s(t_params *p)
{
	int	x_offset;
	int	y_offset;

	x_offset = p->player.pos_x - p->player.del_x * 7;
	y_offset = p->player.pos_y - p->player.del_y * 7;
	if (p->map.map[y_offset / C_S][x_offset / C_S] == '0')
	{
		p->player.pos_x -= (2 * p->player.del_x);
		p->player.pos_y -= (2 * p->player.del_y);
	}
	return (0);
}

int	key_a(t_params *p)
{
	int	x_offset;
	int	y_offset;

	x_offset = p->player.pos_x + p->player.strafe_del_x * 7;
	y_offset = p->player.pos_y + p->player.strafe_del_y * 7;
	if (p->map.map[y_offset / C_S][x_offset / C_S] == '0')
	{
		p->player.pos_x += (2 * p->player.strafe_del_x);
		p->player.pos_y += (2 * p->player.strafe_del_y);
	}
	return (0);
}

int	key_d(t_params *p)
{
	int	x_offset;
	int	y_offset;

	x_offset = p->player.pos_x - p->player.strafe_del_x * 7;
	y_offset = p->player.pos_y - p->player.strafe_del_y * 7;
	if (p->map.map[y_offset / C_S][x_offset / C_S] == '0')
	{
		p->player.pos_x -= (2 * p->player.strafe_del_x);
		p->player.pos_y -= (2 * p->player.strafe_del_y);
	}
	return (0);
}
