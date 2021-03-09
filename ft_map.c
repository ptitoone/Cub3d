/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/09 09:09:08 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/get_next_line.h"
#include "incls/cub.h"
#include "incls/ft_map.h"

static int	ft_is_tex_spec(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C')
		return (1)
	return (0);
}

static int	ft_add_info(char *line, t_params *p)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == 'R')
			if (ft_parse_res(line))
				return (1);
		else if (ft_is_tex_spec(line[i]))
			if (ft_parse_tex(line))
				return (1);
		i++;
	}
	return (0);
}

int	ft_parse_map(char *map_file, t_params *p)
{
	int		map;
	int 	i;
	char	*line;

	p->win_w = 1280;
	p->win_h = 720;

	map = open(map_file, O_RDONLY);
	i = 0;
	while (get_next_line(map, &line) == 1 && i < 8)
	{
		if (line[0] == '\n')
			continue ;
		if (ft_add_info(line, p))
			i++;
		free(line);
	}
	return (0);
}
