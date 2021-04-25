/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:44:29 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/18 11:30:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/libft.h"

char	*ft_strdup(const char *str)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (sdup == NULL)
		return (NULL);
	while (str[i] != 0)
	{
		sdup[i] = str[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
