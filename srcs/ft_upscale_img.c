/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upscale_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:19 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/25 12:44:44 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_upscale_img(int w, int h, int scale, char *img, char *img2)
{
	int		x;
	int		y;
	int		j;
	int		r;
	char 	*pix;
	char 	*new_pix;

	x = 0;
	y = 0;
	j = 0;
	r = 0;
	pix = img;
	new_pix = img2;
	while (r < (h * scale) * (w * scale))
	{
		while (j < scale) 
		{
			while (x < w)
			{
				while (y < scale)
				{
					*(unsigned int *)new_pix = *(unsigned int *)pix;
					new_pix += sizeof(int);
					y++;
					r++;
				}
				pix += sizeof(int);
				y = 0;
				x++;
			}
			pix -= (w + 1) * sizeof(int);
			j++;
			x = 0;
		}
		j = 0;
		i++;
		pix += (w + 1) * sizeof(int);
	}
}
