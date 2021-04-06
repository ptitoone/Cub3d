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

int	ft_keys(int keycode, void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	if (keycode == K_w)
		p->keys.w = 1;
	if (keycode == K_a)
		p->keys.a = 1;
	if (keycode == K_s)
		p->keys.s = 1;
	if (keycode == K_d)
		p->keys.d = 1;
	if (keycode == K_a_l)
		p->keys.l = 1;
	if (keycode == K_a_r)
		p->keys.r = 1;
	if (keycode == K_esc)
	{
		mlx_destroy_window(p->mlx, p->win2);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
