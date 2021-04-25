/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	calc_dist(double x0, double x1, double y0, double y1)
{
	double	dist;

	dist = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	return (dist);
}
