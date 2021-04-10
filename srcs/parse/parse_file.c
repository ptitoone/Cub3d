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

#include "cub.h"
#include "parse.h"
#include "utils.h"
#include "errors.h"
#include "get_next_line.h"

static int	add_parameter(char *line, t_params *p)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
 		if (line[i] == 'R')
		{
			if (parse_res(line, p))
				return (1);
			else
				return (0);
		}
 		else if (is_tex_specifier(line[i]))
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
	if (map_fd < 0)
		return (throw_error(strerror(errno)));
	line = NULL;
	i = 0;
	while (get_next_line(map_fd, &line) == 1)
	{
		if (line[0] == '\0')
			free_line(&line);
		else if (add_parameter(line, p))
			i++;
		else
		{
			free_line(&line);
			return (0);
		}
		if (i == 8)
			break ;
		free_line(&line);
	}
	if (parse_map_size(map_fd, p))
			return (1);
	return (0);
}
