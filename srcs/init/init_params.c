/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 16:16:35 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void init_images(t_params *p)
{
	p->imgv.img = mlx_new_image(p->mlx, (p->win_w), (p->win_h));
	p->imgv.addr = mlx_get_data_addr(p->imgv.img, &p->imgv.bpp,
			&p->imgv.line_len, &p->imgv.endian);
}

static	void init_map(t_params *p)
{
	p->map.c_s = 64;
	p->map.block_h = 64;
}

static	void init_player(t_params *p)
{
	if (p->player.start_dir == NO)
	{
		p->player.orient = 3 * PI / 2;
		p->player.strafe_orient = PI;
	}
	else if (p->player.start_dir == SO)
	{
		p->player.orient = PI / 2;
		p->player.strafe_orient = 0;
	}
	else if (p->player.start_dir == WE)
	{
		p->player.orient = 0;
		p->player.strafe_orient = 3 * PI / 2;
	}
	else if (p->player.start_dir == EA)
	{
		p->player.orient = PI;
		p->player.strafe_orient = PI / 2;
	}
	p->player.pos_x = ((p->player.pos_block_x + 1) * p->map.c_s) - (p->map.c_s / 2);
	p->player.pos_y = ((p->player.pos_block_y + 1) * p->map.c_s) - (p->map.c_s / 2);
}

int	init_params(t_params *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		return (throw_error(ERR_MLX_FAIL));
	p->ratio = p->win_w / p->win_h;
	p->win2 = mlx_new_window(p->mlx, (p->win_w), (p->win_h), "FPV");
	init_images(p);
	init_map(p);
	if (p->player.start_dir == -1)
		return (throw_error(ERR_MAP_NO_POS));
	init_player(p);
	return (1);
}
