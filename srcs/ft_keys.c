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

int	ft_keys(int keycode, void *pr)
{
	int pix;
	int pos_x_offset;
	int pos_y_offset;
	t_params *p;

	pix = 1;
	pos_x_offset = 0;
	pos_y_offset = 0;
	p = (t_params *)pr;
	if (keycode == K_s)
	{
		pos_x_offset = p->player.pos_x - p->player.del_x;
		pos_y_offset = p->player.pos_y - p->player.del_y;
		while (pix-- > 0)
		{
			{
				p->player.pos_x -= p->player.del_x;
				p->player.pos_y -= p->player.del_y;
			}
//			ft_draw_map(p);
//			printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			ft_find_wall(p);
//			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_z)
	{
		pos_x_offset = p->player.pos_x + p->player.del_x;
		pos_y_offset = p->player.pos_y + p->player.del_y;
		while (pix-- > 0)
		{
			if (p->map.map[pos_y_offset/p->map.block_w][pos_x_offset/p->map.block_w] != '1')
			{
				
				p->player.pos_x += p->player.del_x;
				p->player.pos_y += p->player.del_y;
			}
//			ft_draw_map(p);
//			printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			ft_find_wall(p);
//			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_q)
	{
		while (pix-- > 0)
		{
			p->player.orient -= 0.1;
			if (p->player.orient < 0)
				p->player.orient += (2 * PI);
			p->player.del_x = cos(p->player.orient) * 5;
			p->player.del_y = sin(p->player.orient) * 5;
//			ft_draw_map(p);
//			printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			ft_find_wall(p);
//			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_d)
	{
		while (pix-- > 0)
		{

			p->player.orient += 0.1;
			if (p->player.orient > (2 * PI))
				p->player.orient -= (2 * PI);
			p->player.del_x = cos(p->player.orient) * 5;
			p->player.del_y = sin(p->player.orient) * 5;
//			ft_draw_map(p);
//			printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
//			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			ft_find_wall(p);
//			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_esc)
	{
//		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
//	printf("orient = %f\n", p->player.orient);
	return (0);
}
