/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/23 15:47:45 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	int ft_init_tex(t_params *p)
{
	int	i;

	i = -1;
	while (i++ < 4)
		p->tex.dir[i] = NULL;
	p->tex.sp = NULL;
	p->tex.f = NULL;
	p->tex.c = NULL;
}

static	int ft_init_player(t_params *p)
{
	p->player.pos_x = 272;
	p->player.pos_y = 272;
	p->player.del_x = 0;
	p->player.del_y = 0;
	p->player.orient = PI;
}

static	int ft_init_map(t_params *p)
{
	p->map.map_w = 0;
	p->map.map_h = 0;
	p->map.block_w = 0;
	p->map.block_h = 0;
	p->map.map_h = 0;
	p->map.map = NULL;
}

static	int ft_init_imgs(t_params *p)
{
	p->img.img = NULL;
	p->img.addr = NULL;
	p->img.bpp = 0;
	p->img.line_len = 0;
	p->img.endian = 0;
	p->imgv.img = NULL;
	p->imgv.addr = NULL;
	p->imgv.bpp = 0;
	p->imgv.line_len = 0;
	p->imgv.endian = 0;
}

void	ft_init_params(t_params *p)
{
	p->mlx = NULL;
	p->win = NULL;
	p->win_w = 0;
	p->win_h = 0;
	p->ratio = 0;
	ft_init_tex(p);
	ft_init_player(p);
	ft_init_map(p);
	ft_init_imgs(p);
}
