/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:23 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 16:16:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"
#include "errors.h"

static void	set_player_pos(t_params *p, char pos, t_coords *c, int *pos_found)
{
	if (pos == 'N')
		p->player.start_dir = NO;
	else if (pos == 'S')
		p->player.start_dir = SO;
	else if (pos == 'E')
		p->player.start_dir = WE;
	else if (pos == 'W')
		p->player.start_dir = EA;
	p->map.map[(int)c->y][(int)c->x] = '0';
	p->player.pos_block_x = (int)c->x;
	p->player.pos_block_y = (int)c->y;
	*pos_found += 1;
}

int	check_player_pos(t_params *p)
{
	t_coords	coords;
	static int	pos_found;

	coords.x = 0;
	coords.y = 0;
	while (coords.y < p->map.map_h)
	{
		while (coords.x < p->map.map_w)
		{
			if (is_pos(p->map.map[(int)coords.y][(int)coords.x]))
				set_player_pos(
					p,
					p->map.map[(int)coords.y][(int)coords.x],
					&coords,
					&pos_found);
			if (pos_found > 1)
				return (throw_error(ERR_MAP_DUP_POS));
			coords.x++;
		}
		coords.x = 0;
		coords.y++;
	}
	if (!pos_found)
		return (throw_error(ERR_MAP_NO_POS));
	return (1);
}
