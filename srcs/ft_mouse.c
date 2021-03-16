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

int ft_mouse(int button, int x, int y, void *pr)
{
	t_params *p;
	int pix;
	int pix2;
	int z;
	int w;

	pix  = 10;
	pix2 = 10;
	x = x - 5;
	y = y - 5;
	z = x;
	w = y;
	p = (t_params *)pr;
	if (button == M_l)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0050050050);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	if (button == M_r)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0150150150);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	if (button == M_u)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0070010070);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	return (0);
}
