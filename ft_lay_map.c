/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lay_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptito <akotzky@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:33:22 by ptito             #+#    #+#             */
/*   Updated: 2021/03/15 07:56:00 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/ft_map.h"
#include "incls/get_next_line.h"
#include "incls/cub.h"

static int	ft_lay_map_line(char *l, int i, t_map *m)
{
	int	j;

	j = 0;
	m->map[i] = (char *)malloc(sizeof(char) * (m->map_w + 1));
	if (m->map[i] == NULL)
		return (0);
	while (l[j])
	{
		m->map[i][j] = l[j];
		j++;
	}
	m->map[i][j] = 0;
	return (1);
}

static int	ft_is_map_top(char *l)
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
		return (1);
	return (0);
}

int	ft_lay_map(char *map_file, t_map *m)
{
	int		i;
	int		map_fd;
	char	*line;

	i = 0;
	map_fd = open(map_file, O_RDONLY);
	line = NULL;
	m->map = (char **)malloc(sizeof(char *) * m->map_h);
	if (m->map == NULL)
		return (0);
	while (get_next_line(map_fd, &line) == 1)
	{
		if (ft_is_map_top(line))
		{
			ft_lay_map_line(line, i++, m);
			free(line);
			line = NULL;
			while (i < m->map_h)
			{
				if (get_next_line(map_fd, &line) == 1)
				{
					ft_lay_map_line(line, i++, m);
					free(line);
					line = NULL;
				}
			}
			close(map_fd);
			return (1);
		}
		free(line);
		line = NULL;
	}
	return (0);
}
