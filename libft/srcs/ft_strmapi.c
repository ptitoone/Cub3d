/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:45:30 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/22 13:39:17 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str != NULL)
	{
		while (s[i] != 0)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
