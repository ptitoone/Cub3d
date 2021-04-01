/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tex_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:40:16 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/31 17:33:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_tex_col(char tex[16][16], int tex_x, int tex_y, int rc, int j, t_img *img)
{
	int i;
	if (tex[tex_x][tex_y] == '1')
		my_mlx_pixel_put(img, rc, j, 0x00000000);
	else
		my_mlx_pixel_put(img, rc, j, 0x00FFFFFF);
}
