/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:45:48 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/19 14:01:09 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *chain, const char *key, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (key[i] == 0)
		return ((char *)chain);
	while (chain[i] != 0 && i != n)
	{
		if (key[j] == 0)
			return ((char *)chain);
		while (chain[i + j] == key[j] && (i + j) != n)
		{
			j++;
			if (key[j] == '\0')
				return ((char *)&chain[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
