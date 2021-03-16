/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:45:53 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/20 14:46:59 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = ft_strlen(s);
	ch = c;
	s += len;
	while (len >= 0)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}
