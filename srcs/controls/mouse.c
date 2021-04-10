/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:26 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/29 13:42:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
static int	mouse_a(t_params *p)
{
	p->player.orient -= 0.07;
	p->player.strafe_orient -= 0.07;
	if (p->player.orient < 0)
		p->player.orient += (2 * PI);
	if (p->player.strafe_orient < 0)
		p->player.strafe_orient += (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	p->player.strafe_del_x = cos(p->player.strafe_orient) * 5;
	p->player.strafe_del_y = sin(p->player.strafe_orient) * 5;
	return (0);
}

static int	mouse_d(t_params *p)
{
	p->player.orient += 0.07;
	p->player.strafe_orient += 0.07;
	if (p->player.orient > (2 * PI))
		p->player.orient -= (2 * PI);
	if (p->player.orient > (2 * PI))
		p->player.strafe_orient -= (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	p->player.strafe_del_x = cos(p->player.strafe_orient) * 5;
	p->player.strafe_del_y = sin(p->player.strafe_orient) * 5;
	return (0);
}

int	mouse(int x, int y, void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	if (x < (p->win_w / 2) - 1)
		mouse_a(p);
	else if (x >= (p->win_w / 2) + 1)
		mouse_d(p);
	return (0);
}
