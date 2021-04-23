/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub.h"

int	init_params(t_params *p);
int	check_player_pos(t_params *p);
int	init_sprites(t_params *p);
int	init_tex_img(t_params *p);
int	init_map(char *map_file, t_params *p);

#endif