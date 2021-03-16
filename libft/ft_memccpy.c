/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:33:40 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/22 07:37:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*(unsigned char *)src == ch)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return ((void *)dst + 1);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (NULL);
}
