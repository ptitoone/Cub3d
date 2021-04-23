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
#include "throw_error.h"

int	is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_tex_spec(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

int	is_sprite_spec(char c)
{
	if (c == '2')
		return (1);
	return (0);
}

int	is_map_vert_end_line(char const *l)
{
	int	i;

	i = 0;
	while (l[i] == ' ' || l[i] == '0')
		i++;
	if (l[i] == '1')
	{
		while (((l[i] == ' '
				 || l[i] == '0'
				 || l[i] == '1') && l[i] != 0))
			i++;
		if (l[i] == 0)
			return (1);
	}
	return (0);
}

int	is_valid_map_line(char const *l)
{
	int	i;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] == 0)
		return (0);
	while (l[i] == ' '
		   || l[i] == '0'
		   || l[i] == '1'
		   || is_sprite_spec(l[i])
		   || is_pos(l[i]))
		i++;
	if (l[i] == 0)
		return (1);
	return (0);
}
