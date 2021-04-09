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

static int	is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	is_map_line(char const *l, t_params *p)
{
	int			i;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] == 0)
		return (0);
	while (l[i] == ' '
		|| l[i] == '0'
		|| l[i] == '1'
		|| l[i] == '2'
		|| is_pos(l[i]))
		i++;
	if (l[i] == 0)
	{
		if (i >= p->map.map_w)
			p->map.map_w = i + 1;
		p->map.map_h++;
		return (1);
	}
	return (0);
}

int	parse_map_size(int map_fd, t_params *p)
{
	char *line;

	line = NULL;
	while(get_next_line(map_fd, &line) == 1 && !(is_map_line(line, p)))
		free_line(&line);
	if (p->map.map_w == 1)
	{
		free_line(&line);
		while (get_next_line(map_fd, &line) == 1 && is_map_line(line, p))
			free_line(&line);
		free_line(&line);
		return (1);
	}
	return (throw_error(ERR_MAP_NF));
}
