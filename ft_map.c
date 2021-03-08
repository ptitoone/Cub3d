/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/08 17:37:11 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incls/get_next_line.h"
#include "incls/cub.h"
#include "incls/ft_map.h"

int		ft_parse_map(char *map_file, t_params *p)
{
	int		map;
//	int 	i;
//	int 	i;
	char	*line;

	p->win_w = 1280;
	p->win_h = 720;

	map = open(map_file, O_RDONLY);
	get_next_line(map, &line);
//	i = 0;
//	j = 0;
/*	while (i < 8)
	{
		while (line[j] != 0)
		{
			if (line[j] == '\n')
				break ;
			else if (line[j] == 'R')i
			{
				if(ft_parse_res(line, &p))
					i++;
				else
					break ;
			}
			j++;
		}*/
		free(line);
		/*get_next_line(map, &line);
	}
*/

}

