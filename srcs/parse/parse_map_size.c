/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:22:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 14:44:25 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line.h"

static int	is_pos(char c, int *pos_found)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		*pos_found += 1;
		return (1);
	}
	return (0);
}

static int	is_map_h_limit(char *l, t_params *p)
{
	int i;

	i = 0;
	while (l[i] ==  ' ')
		i++;
	if (l[i] != '1')
		return (0);
	while (l[i] == '1')
		i++;
	if (l[i] == ' ')
		while (l[i] == ' ')
			i++;
	if (l[i] == 0)
	{
		p->map.map_h++;
		return (1);
	}
	return (0);
}

static int	is_map_line(char *l, t_params *p)
{
	int			i;
	static int	pos_found;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] != '1')
		return (throw_error(ERR_MAP_INV_WALL));
	while (l[i + 1] != 0)
	{
		if (!(l[i] == ' ' || l[i] == '0' || l[i] == '1' || l[i] == '2' || is_pos(l[i], &pos_found)))
			return (throw_error(ERR_MAP_INV));
		i++;
	}
	if (pos_found > 1)
		return (throw_error(ERR_MAP_DUP_POS));
	if (i >= p->map.map_w)
		p->map.map_w = i;
	while (l[i] == ' ' && i > 0)
		i--;
	if (l[i] == '1')
	{
		p->map.map_h++;
		return (1);
	}
	return (throw_error(ERR_MAP_INV_WALL));
}

int	parse_map_size(int map_fd, t_params *p)
{
	char *line;

	line = NULL;
	while(get_next_line(map_fd, &line) == 1)
	{
		if (is_map_h_limit(line, p))
		{
			free(line);
			line = NULL;
			while(get_next_line(map_fd, &line) == 1)
			{
				if (is_map_h_limit(line, p))
				{
					free(line);
					return (1);
				}
				else if (!(is_map_line(line, p)))
				{
					free(line);
					return (0);
				}
				free(line);
				line = NULL;
			}
		}
		free(line);
		line = NULL;
	}
	return (1);
}
