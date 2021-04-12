/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:23:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 10:24:02 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;
/*	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;*/

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}
