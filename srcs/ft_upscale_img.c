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

void	*ft_upscale_img(int w, int h, int scale, void *img)
{
	int		x;
	int		y;
	int		i;
	int 	new_pix_count;
	void	*new_img;
	char *pix;

	x = 0;
	y = 0;
	i = -1;
	new_pix_count = ((h * x) * scale); 
	new_img = (void *)malloc(new_pix_count * sizeof(int));
	if (img == NULL)
		return (NULL);
	while (i++ < w * h)
	{
		while (x < scale)
		{
			while (y < scale)
			{
				*new_img = (int)img;
				new_img += sizeof(int);
				y++;
			}
			img += sizeof(int);
			y  = 0;
			x++;
		}
		img -= (x * w);
		x = 0;
		i++;
		img += sizeof(int);
	}
	return (new_img);
}
