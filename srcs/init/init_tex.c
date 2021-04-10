/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:08:40 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:23:30 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "errors.h"

int	init_tex_img(t_params *p)
{
	int	w;
	int	h;

	p->tex.no.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[NO], &w, &h);
	if (p->tex.no.img == NULL)
		return (throw_error(ERR_TEX_NO_OF));
	p->tex.no.addr = mlx_get_data_addr(p->tex.no.img, &p->tex.no.bpp,
			&p->tex.no.line_len, &p->tex.no.endian);
	p->tex.so.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[SO], &w, &h);
	if (p->tex.so.img == NULL)
		return (throw_error(ERR_TEX_SO_OF));
	p->tex.so.addr = mlx_get_data_addr(p->tex.so.img, &p->tex.so.bpp,
			&p->tex.so.line_len, &p->tex.so.endian);
	p->tex.we.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[WE], &w, &h);
	if (p->tex.we.img == NULL)
		return (throw_error(ERR_TEX_WE_OF));
	p->tex.we.addr = mlx_get_data_addr(p->tex.we.img, &p->tex.we.bpp,
			&p->tex.we.line_len, &p->tex.we.endian);
	p->tex.ea.img = mlx_xpm_file_to_image(p->mlx, p->tex.dir[EA], &w, &h);
	if (p->tex.ea.img == NULL)
		return (throw_error(ERR_TEX_EA_OF));
	p->tex.ea.addr = mlx_get_data_addr(p->tex.ea.img, &p->tex.ea.bpp,
			&p->tex.ea.line_len, &p->tex.ea.endian);
	return (1);
}
