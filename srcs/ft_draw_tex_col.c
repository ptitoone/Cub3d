/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tex_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:40:32 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/29 17:28:02 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_tex_col(char tex[16][16], int index_x, int index_y, int count, t_img *img)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (tex[index][i] == '1')
			my_mlx_pixel_put(img, index_x, i, 0x00FFFFFF);	
		else
			my_mlx_pixel_put(img, index_x, i, 0x00000000);	
		i++;
	}
}
