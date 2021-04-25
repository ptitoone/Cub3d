/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:17:41 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "errors.h"

int	throw_error(char *error)
{
	ft_putstr_fd("Error\n", 1);
	//ft_putstr_fd(error, 2);
	return (0);
}
