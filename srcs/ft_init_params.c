/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 16:16:35 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void ft_init_player(t_params *p)
{
	p->player.orient = PI;
	p->player.strafe_orient = PI / 2;
	p->player.start_dir = -1;
}

static	void ft_init_map(t_params *p)
{
	p->map.c_s = 64;
	p->map.block_h = 64;
}

static void ft_init_imgs(t_params *p)
{
	p->imgv.img = mlx_new_image(p->mlx, (p->win_w), (p->win_h));
	p->imgv.addr = mlx_get_data_addr(p->imgv.img, &p->imgv.bpp,
			&p->imgv.line_len, &p->imgv.endian);
}

int	ft_init_params(t_params *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		return (throw_error(ERR_MLX_FAIL));
	p->ratio = p->win_w / p->win_h;
	p->win2 = mlx_new_window(p->mlx, (p->win_w), (p->win_h), "FPV");
	ft_init_player(p);
	ft_init_map(p);
	ft_init_imgs(p);
	return (1);
}
