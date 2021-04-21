/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:23 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 16:16:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"
#include "utils.h"
#include "get_next_line.h"

static int	lay_map_line(char *l, int i, t_params *p)
{
	int	j;

	j = 0;
	p->map.map[i] = (char *)malloc(sizeof(char) * (p->map.map_w + 1));
	if (p->map.map[i] == NULL)
		return (0);
	while (l[j] == ' ' || l[j] == '0'
		|| l[j] == '1' || is_sprite_spec(l[j])
		|| is_pos(l[j]))
	{
		if (l[j] == ' ')
			p->map.map[i][j] = '0';
		else
			p->map.map[i][j] = l[j];
		j++;
	}
	while (j < p->map.map_w)
		p->map.map[i][j++] = '0';
	p->map.map[i][j] = 0;
	return (1);
}

static int	is_map_vert_end_line(char const *l)
{
	int	i;

	i = 0;
	while (l[i] == ' ' || l[i] == '0')
		i++;
	if (l[i] == '1')
	{
		while (((l[i] == ' '
					 || l[i] == '0'
					 || l[i] == '1') && l[i] != 0))
			i++;
		if (l[i] == 0)
			return (1);
	}
	return (0);
}

int	lay_map(char *map_file, t_params *p)
{
	int		i;
	int		map_fd;
	char	*line;

	i = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		perror("Error : ");
	line = NULL;
	p->map.map = (char **)malloc(sizeof(char *) * p->map.map_h);
	if (p->map.map == NULL)
		return (0);
	while (get_next_line(map_fd, &line) == 1 && !(is_map_vert_end_line(line)))
		free_line(&line);
	lay_map_line(line, i++, p);
	free_line(&line);
	while (i < p->map.map_h)
	{
		get_next_line(map_fd, &line);
		lay_map_line(line, i++, p);
		free_line(&line);
	}
	close(map_fd);
	return (1);
}
