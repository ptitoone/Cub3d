/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:34:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 15:58:11 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_keys(int keycode, void *pr)
{
	int pix;

	pix = 1;
	t_params *p;

	p = (t_params *)pr;
	if (keycode == K_s)
	{
		while (pix-- > 0)
		{
			ft_draw_map(p);
			ft_draw_player(p->player.pos_x, ++p->player.pos_y, p);
			printf("color = %u\n", ft_get_pixel_color(&p->img, p->player.pos_x, p->player.pos_y));
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_z)
	{
		while (pix-- > 0)
		{
			ft_draw_map(p);
			ft_draw_player(p->player.pos_x, --p->player.pos_y, p);
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_q)
	{
		while (pix-- > 0)
		{
			ft_draw_map(p);
			ft_draw_player(--p->player.pos_x, p->player.pos_y, p);
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_d)
	{
		while (pix-- > 0)
		{
			ft_draw_map(p);
			ft_draw_player(++p->player.pos_x, p->player.pos_y, p);
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_a_r)
	{
		while (pix-- > 0)
		{
			p->player.orient += 0.1;
			ft_draw_map(p);
			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_a_l)
	{
		while (pix-- > 0)
		{
			p->player.orient -= 0.1;
			ft_draw_map(p);
			ft_draw_player(p->player.pos_x, p->player.pos_y, p);
			mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
		}
	}
	if (keycode == K_esc)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
	printf("orient = %f\n", p->player.orient);
	return (0);
}
