/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:34:27 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/20 14:29:10 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		neg;
	int		i;

	num = 0;
	neg = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = 1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != 0)
	{
		num *= 10;
		num += str[i++] - 48;
	}
	if (neg == 1)
		return (num = -num);
	return (num);
}
