/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tex_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:40:32 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/30 11:43:40 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_tex_col(char tex[16][16], int tex_x, int tex_y, int rc, int j, t_img *img)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (tex[tex_x][index_y] == '1')
			my_mlx_pixel_put(img, rc, j, 0x00FFFFFF);	
		else
			my_mlx_pixel_put(img, rc, j, 0x00000000);	
		i++;
	}
}
