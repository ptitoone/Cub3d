/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:22:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/10 14:44:25 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_tex_specifier(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

int extract_rgb_value(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	if (str[i++] == 'F' || str[i] == 'C')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] >= '1' && str[i] <= '9')
			j++;

	}

}
