/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:34:59 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/18 09:35:02 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	p = malloc(nitems * size);
	if (p != NULL)
		ft_bzero(p, nitems * size);
	return (p);
}
