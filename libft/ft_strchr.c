/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:44:07 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/22 13:35:48 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == 0)
	{
		while (*s != 0)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != 0)
		{
			if (*s == ch)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}
