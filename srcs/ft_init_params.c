/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 11:02:22 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void ft_init_tex(t_params *p)
{
	int	i;

	i = -1;
	while (i++ < 4)
		p->tex.dir[i] = NULL;
	p->tex.sp = NULL;
	p->tex.f = NULL;
	p->tex.c = NULL;
//	p->tex.wall.img = NULL;
//	p->tex.wall.addr = NULL;
//	p->tex.wall.bpp = 0;
//	p->tex.wall.line_len = 0;
//	p->tex.wall.endian = 0;
}

static	void ft_init_player(t_params *p)
{
	p->player.pos_x = 0;
	p->player.pos_y = 0;
	p->player.del_x = 0;
	p->player.del_y = 0;
	p->player.orient = PI;
	p->player.strafe_orient = PI / 2;
	p->player.strafe_del_x = 0;
	p->player.strafe_del_y = 0;
	p->player.start_dir = -1;
}

static	void ft_init_map(t_params *p)
{
	p->map.map_w = 0;
	p->map.map_h = 0;
	p->map.c_s = 0;
	p->map.block_h = 0;
	p->map.map_h = 0;
	p->map.map = NULL;
}

static	void ft_init_imgs(t_params *p)
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
	p->win_w = -1;
	p->win_h = -1;
	p->ratio = 0;
	ft_init_tex(p);
	ft_init_player(p);
	ft_init_map(p);
	ft_init_imgs(p);
	ft_init_keys(&p->keys);
}
