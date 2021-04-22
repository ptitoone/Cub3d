/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
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
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	return (0);
}

int check_errors(char *file_name)
{
	if (check_file_validity(file_name))
		return (1);
	return (0);
}

int	check_map_validity(char **map, int height)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	len = 0;
	while (map[y][x++] != 0)
		len++;
	x = 0;
	while (y < height)
	{
		while (map[y][x] != 0)
			x++;
		if ((x - len) >= 2 || (len - x) >= 2)
			return (throw_error(ERR_MAP_INV_WALL));
		len = x;
		x = 0;
		y++;
	}
	return (1);
}
