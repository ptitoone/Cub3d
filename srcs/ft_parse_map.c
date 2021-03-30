/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/24 10:16:06 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub.h"
#include "ft_map.h"

static int	ft_is_tex_spec(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

static int	ft_add_info(char *line, t_params *p)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
 		if (line[i] == 'R')
		{
 			if (ft_parse_res(line, p))
 				return (1);
		}
		else if (ft_is_tex_spec(line[i]))
		{
			if (ft_parse_tex(line, &p->tex))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parse_map(char *map_file, t_params *p)
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
		if (ft_add_info(line, p))
			i++;
		else
			return (0);
		free(line);
		line = NULL;
		if (i == 8)
			break ;
	}
	if (ft_parse_map_size(map_fd, p))
	{
		if (ft_lay_map(map_file, &p->map))
		{
			p->map.c_s = p->win_w / 16;
			p->map.block_h = p->win_h / 16;
			return (1);
		}
	}
	return (0);
}
