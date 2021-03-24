/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upscale_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:19 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/24 15:39:44 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_upscale_img(int w, int h, int scale, char *img, char *img2)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char 	*pix;
	char 	*new_pix;

	x = 0;
	y = 0;
	j = 0;
	i = -1;
	pix = img;
	new_pix = img2;
	while (i++ < h * w)
	{
		while (j < scale)
		{
			while (x < w)
			{
				while (y < scale)
				{
					*(unsigned int *)new_pix = *(unsigned int *)pix;
					new_pix += 4;
					y++;
				}
				pix += 4;
				y = 0;
				x++;
			}
			pix -= w * 4;
			j++;
		}
		j = 0;
		x = 0;
		i++;
		pix += (w + 1) * 4;
	}
}
