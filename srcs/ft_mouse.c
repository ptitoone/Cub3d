/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:26 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/29 13:42:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
static int	ft_mouse_a(t_params *p)
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
//	ft_find_wall(p);
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_mouse_d(t_params *p)
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
//	ft_find_wall(p);
//	ft_draw_map(p);
//	printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

int ft_mouse(int x, int y, void *pr)
{
	t_params *p;
	p = (t_params *)pr;
	if (x < (p->win_w / 2) - 1)
		ft_mouse_a(p);
	else if (x >= (p->win_w / 2) + 1)
		ft_mouse_d(p);
	return (0);
}
