/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:42:34 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/20 14:01:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (n-- > 0)
		if (*(unsigned char *)s++ == ch)
			return ((unsigned char *)s - 1);
	return (NULL);
}
