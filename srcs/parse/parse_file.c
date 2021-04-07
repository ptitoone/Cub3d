/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:00:58 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub.h"
#include "parse.h"

static int	is_tex_spec(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

static int	add_info(char *line, t_params *p)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
 		if (line[i] == 'R')
		{
			if (p->win_h == 0 && p->win_w == 0)
			{
 				if (parse_res(line, p))
 					return (1);
			}
			else
				return (throw_error(ERR_RES_DUP));
		}
		else if (is_tex_spec(line[i]))
		{
			if (parse_tex(line, &p->tex))
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse_file(char *map_file, t_params *p)
{
	int		map_fd;
	int 	i;
	char	*line;

	map_fd = open(map_file, O_RDONLY);
	line = NULL;
	i = 0;
	while (get_next_line(map_fd, &line) == 1)
	{
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue ;
		}
		if (add_info(line, p))
			i++;
		else
			return (0);
		free(line);
		line = NULL;
		if (i == 8)
			break ;
	}
	if (parse_map_size(map_fd, p))
	{
		if (lay_map(map_file, p))
			return (1);
	}
	return (0);
}
