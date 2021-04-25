/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:44:56 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/22 09:02:33 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
