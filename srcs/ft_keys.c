/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:34:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/25 12:50:20 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ft_map.h"

static int	ft_key_w(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x + p->player.del_x;
	y_offset = p->player.pos_y + p->player.del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x += (2 * p->player.del_x);
		p->player.pos_y += (2 * p->player.del_y);
	}
	ft_find_wall(p);
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_s(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x + p->player.del_x;
	y_offset = p->player.pos_y + p->player.del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x -= p->player.del_x;
		p->player.pos_y -= p->player.del_y;
	}
	ft_find_wall(p);
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_a(t_params *p)
{
	p->player.orient -= 0.1;
	if (p->player.orient < 0)
		p->player.orient += (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	ft_find_wall(p);
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_d(t_params *p)
{
	p->player.orient += 0.1;
	if (p->player.orient > (2 * PI))
		p->player.orient -= (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	ft_find_wall(p);
//	ft_draw_map(p);
//	printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

int	ft_keys(int keycode, void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	while (1)
	{
		if (keycode == K_w)
		{
			ft_key_w(p);
		}
		if (keycode == K_a)
		{
			ft_key_a(p);
		}
		if (keycode == K_s)
		{
			ft_key_s(p);
		}
		if (keycode == K_d)
		{
			ft_key_d(p);
		}
		if (keycode == K_esc)
		{
			mlx_destroy_window(p->mlx, p->win2);
			exit(EXIT_SUCCESS);
		}
		break ;
	}
	return (0);
}
