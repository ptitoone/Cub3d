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
#include "parse.h"

static void	tex_to_array(t_img *img, unsigned int tex[TEX_S][TEX_S])
{
	int	x;
	int	y;

	y = -1;
	while (++y < TEX_S)
	{
		x = -1;
		while (++x < TEX_S)
		{
			tex[y][x] = get_pixel_color(img, x, y);
		}
	}
}

int	init_tex_img(t_params *p)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	while (i < 10)
	{
		if (p->tex.type[i].path)
		{
			p->tex.type[i].img.img = mlx_xpm_file_to_image(p->mlx,
				p->tex.type[i].path, &w, &h);
			if (p->tex.type[i].img.img == NULL)
				return (throw_error(ERR_TEX_NO_OF));
			if (w != C_S && w != C_S)
				return (throw_error(ERR_TEX_INV_SIZE));
			p->tex.type[i].img.addr = mlx_get_data_addr(p->tex.type[i].img.img,
				&p->tex.type[i].img.bpp,
				&p->tex.type[i].img.line_len, &p->tex.type[i].img.endian);
			tex_to_array(&p->tex.type[i].img, p->tex.type[i].t_color_map);
		}
		i++;
	}
	p->tex.f_color = extract_rgb_value(p->tex.f);
	p->tex.c_color = extract_rgb_value(p->tex.c);
	return (1);
}
