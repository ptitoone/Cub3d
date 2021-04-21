/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 15:01:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
#define ENGINE_H

#include "cub.h"

int		check_wall_hit(t_coords *c, t_params *p, double x_offset, double y_offset);
int		check_hori_lines(t_params *p, double ra, t_coords *c);
int		check_vert_lines(t_params *p, double ra, t_coords *c);

void	set_sprite_visible(t_sprite_data *s, int x, int y);
void	calc_sprite_dist(t_params *p);
void	sort_sprites(t_sprite *sprites, int count);
void	calc_sprite_screen_x_pos(t_params *p);

# endif
