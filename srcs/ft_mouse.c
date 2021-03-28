/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:26 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 15:59:14 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
static int	ft_mouse_a(t_params *p)
{
	p->player.orient -= 0.08;
	if (p->player.orient < 0)
		p->player.orient += (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
//	ft_find_wall(p);
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_mouse_d(t_params *p)
{
	p->player.orient += 0.08;
	if (p->player.orient > (2 * PI))
		p->player.orient -= (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
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
	if (x < p->win2, (p->win_w / 2) - 1)
		ft_mouse_a(p);
	else if (x >= p->win2, (p->win_w / 2) + 1)
		ft_mouse_d(p);
	mlx_mouse_move(p->win2, p->win_w / 2, p->win_h / 2);
	return (0);
}
