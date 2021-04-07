/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lay_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:23 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 16:16:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "get_next_line.h"
#include "cub.h"

static int	ft_is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	ft_set_player_pos(t_params *p, char pos, int i, int j)
{
	if (pos == 'N')
		p->player.start_dir = NO;
	else if (pos == 'S')
		p->player.start_dir = SO;
	else if (pos == 'E')
		p->player.start_dir = WE;
	else if (pos == 'W')
		p->player.start_dir = EA;
	p->player.pos_block_x = j;
	p->player.pos_block_y = i;
}

static int	ft_lay_map_line(char *l, int i, t_params *p)
{
	int	j;

	j = 0;
	p->map.map[i] = (char *)malloc(sizeof(char) * (p->map.map_w + 1));
	if (p->map.map[i] == NULL)
		return (0);
	while (l[j] == ' ' || l[j] == '0'
		|| l[j] == '1' || l[j] == '2'
		|| ft_is_pos(l[j]))
	{
		if (l[j] == ' ')
			p->map.map[i][j] = '0';
		else if (ft_is_pos(l[j]))
			ft_set_player_pos(p, l[j], i, j);
		else
			p->map.map[i][j] = l[j];
		j++;
	}
	p->map.map[i][j] = 0;
	return (1);
}

static int	ft_is_map_top(char *l)
{
	int	i;

	i = 0;
	while (l[i] == ' ')
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

int	ft_lay_map(char *map_file, t_params *p)
{
	int		i;
	int		map_fd;
	char	*line;

	i = 0;
	map_fd = open(map_file, O_RDONLY);
	line = NULL;
	p->map.map = (char **)malloc(sizeof(char *) * p->map.map_h);
	if (p->map.map == NULL)
		return (0);
	while (get_next_line(map_fd, &line) == 1)
	{
		if (ft_is_map_top(line))
			break ;
		free(line);
		line = NULL;
	}
	ft_lay_map_line(line, i++, p);
	free(line);
	line = NULL;
	while (i < p->map.map_h)
	{
		get_next_line(map_fd, &line);
		ft_lay_map_line(line, i++, p);
		free(line);
		line = NULL;
	}
	close(map_fd);
	return (1);
}
