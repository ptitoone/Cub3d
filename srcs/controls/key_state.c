/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:34:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 13:23:23 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "utils.h"

int	key_press(int keycode, void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	if (keycode == K_W)
		p->keys.w = 1;
	if (keycode == K_A)
		p->keys.a = 1;
	if (keycode == K_S)
		p->keys.s = 1;
	if (keycode == K_D)
		p->keys.d = 1;
	if (keycode == K_A_L)
		p->keys.l = 1;
	if (keycode == K_A_R)
		p->keys.r = 1;
	if (keycode == K_ESC)
	{
		free_params(p);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_release(int keycode, void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	if (keycode == K_W)
		p->keys.w = 0;
	if (keycode == K_A)
		p->keys.a = 0;
	if (keycode == K_S)
		p->keys.s = 0;
	if (keycode == K_D)
		p->keys.d = 0;
	if (keycode == K_A_L)
		p->keys.l = 0;
	if (keycode == K_A_R)
		p->keys.r = 0;
	return (0);
}
