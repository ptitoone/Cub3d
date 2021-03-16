/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:59:05 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/25 14:14:57 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	if (str)
	{
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			j--;
			i++;
		}
	}
}
