/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:22:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line.h"

static int	ft_is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	ft_is_map_h_limit(char *l, t_params *p)
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

static int	ft_is_map_line(char *l, t_params *p)
{
	int i;
	int pos_found;
	
	i = 0;
	pos_found = 0;
	while (l[i] ==  ' ')
		i++;
	if (l[i] != '1')
		return (0);
	i++;
	while ((l[i] == '0' || l[i] == '1' || l[i] == '2' || l[i] == ' ' || ft_is_pos(l[i]))
		&& l[i] != 0)
	{
		if (ft_is_pos(l[i]))
			pos_found++;
		if (pos_found > 1)
			return (0);
		i++;
	}
	if (i >= p->map.map_w)
		p->map.map_w = i;
	while (l[i] != '1' && i > 0)
		i--;
	if (l[i] == '1')
	{
		p->map.map_h++;
		return (1);
	}
	return (0);
}

int	ft_parse_map_size(int map_fd, t_params *p)
{
	char *line;
	
	while(get_next_line(map_fd, &line) == 1)
	{
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue ;
		}
		if (ft_is_map_h_limit(line, p))
		{
			free(line);
			line = NULL;
			while(get_next_line(map_fd, &line) == 1)
			{
				if (ft_is_map_h_limit(line, p))
					return (1);
				else if (ft_is_map_line(line, p))
				{
					free(line);
					line = NULL;
					continue ;
				}
				return (0);
			}
		}
		free(line);
		line = NULL;
	}
	return (0);
}
