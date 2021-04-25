/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_validity.c								:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:00:58 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line.h"
#include "errors.h"
#include "utils.h"
#include "parse.h"

static int	check_line(const char *l, t_param_count	*p_count, int i)
{
	while (l[i] == ' ')
		i++;
	if (!l[i])
		return (1);
	else if (l[i] == 'R' && l[i + 1] == ' ')
		p_count->resolution++;
	else if (l[i] == 'N' && l[i + 1] == 'O' && l[i + 2] == ' ')
		p_count->north_tex++;
	else if (l[i] == 'S' && l[i + 1] == 'O' && l[i + 2] == ' ')
		p_count->south_tex++;
	else if (l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		p_count->west_tex++;
	else if (l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		p_count->east_tex++;
	else if (l[i] == 'S' && l[i + 1] == ' ')
		p_count->sprite_tex++;
	else if (l[i] == 'F' && l[i + 1] == ' ')
		p_count->floor_rgb++;
	else if (l[i] == 'C' && l[i + 1] == ' ')
		p_count->ceiling_rgb++;
	else if (l[i])
		return (0);
	return (1);
}

static int	count_params(t_param_count *p_count)
{
	if (p_count->resolution != 1
		|| p_count->north_tex != 1
		|| p_count->south_tex != 1
		|| p_count->west_tex != 1
		|| p_count->south_tex != 1
		|| p_count->sprite_tex != 1
		|| p_count->floor_rgb != 1
		|| p_count->ceiling_rgb != 1)
		return (0);
	return (1);
}

int	check_params(const char *map_file_name)
{
	int						fd;
	char					*line;
	static t_param_count	p_count;

	fd = open(map_file_name, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, &p_count, 0);
		free_line(&line);
	}
	free_line(&line);
	close(fd);
	if (count_params(&p_count))
		return (1);
	return (throw_error(ERR_INVALID_PARAM));
}

static int	is_empty_line(const char *l)
{
	int	i;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (!l[i])
		return (1);
	return (0);
}

int	check_map_presence(char *map_file_name)
{
	int		fd;
	char	*line;

	fd = open(map_file_name, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) == 1 && !is_valid_map_line(line))
		free_line(&line);
	if (!is_map_vert_end_line(line) && !close(fd))
		return (throw_error(ERR_MAP_NF));
	free_line(&line);
	while (get_next_line(fd, &line) == 1 && is_valid_map_line(line))
		free_line(&line);
	if (is_valid_map_line(line) && !close(fd) && free_line(&line))
		return (1);
	free_line(&line);
	while (get_next_line(fd, &line) == 1 && is_empty_line(line))
		free_line(&line);
	if ((is_empty_line(line) || !line) && free_line(&line) && !close(fd))
		return (1);
	free_line(&line);
	close(fd);
	return (throw_error(ERR_INV_LINE_A_MAP));
}
