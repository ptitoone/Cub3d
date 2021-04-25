/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:33:12 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/20 15:18:59 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst - i);
}
