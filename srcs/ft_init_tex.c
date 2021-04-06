/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:08:40 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 12:07:15 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_tex_img(t_params *p)
{
	int w;
	int h;

	p->tex.no.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[NO], &w, &h);
	p->tex.no.addr = mlx_get_data_addr(p->tex.no.img, &p->tex.no.bpp,
			&p->tex.no.line_len, &p->tex.no.endian);
	p->tex.so.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[SO], &w, &h);
	p->tex.so.addr = mlx_get_data_addr(p->tex.so.img, &p->tex.so.bpp,
			&p->tex.so.line_len, &p->tex.so.endian);
	p->tex.we.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[WE], &w, &h);
	p->tex.we.addr = mlx_get_data_addr(p->tex.we.img, &p->tex.we.bpp,
			&p->tex.we.line_len, &p->tex.we.endian);
	p->tex.ea.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[EA], &w, &h);
	p->tex.ea.addr = mlx_get_data_addr(p->tex.ea.img, &p->tex.ea.bpp,
			&p->tex.ea.line_len, &p->tex.ea.endian);
}
