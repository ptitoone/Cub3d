/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:40:16 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/31 17:33:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_tex_col(t_img *tex, int tex_x, int tex_y, int rc, int j, t_img *img)
{
	unsigned int	color;

	color = get_pixel_color(tex, tex_x, tex_y);
	put_pixel(img, rc, j, (int)color);
}
