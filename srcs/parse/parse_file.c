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
#include "../../libft/incls/get_next_line.h"

static int	add_parameter(char *line, t_params *p)
{
	int	i;

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
		else if (is_tex_spec(line[i]))
		{
			if (parse_tex(line, p))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int	parse_file(char *map_file, t_params *p)
{
	int		map_fd;
	int		i;
	char	*line;

	map_fd = open(map_file, O_RDONLY);
	i = 0;
	line = NULL;
	if (map_fd < 0)
		return (throw_error(strerror(errno)));
	while (get_next_line(map_fd, &line) == 1)
	{
		if (add_parameter(line, p))
			i++;
		free_line(&line);
	}
	free_line(&line);
	close(map_fd);
	map_fd = open(map_file, O_RDONLY);
	if (i == 8 && parse_map_size(map_fd, p))
	{
		close(map_fd);
		return (1);
	}
	close(map_fd);
	return (throw_error(ERR_MISSING_PARAM));
}
