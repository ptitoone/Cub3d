/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub.h"

void	free_line(char **line);
int 	free_params(t_params *p);
void	sort_sprites(t_sprite *sprites, int count);
void	calculate_sprite_dist(t_params *p);
void	calculate_sprite_screen(t_params *p);


#endif