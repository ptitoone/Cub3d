/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:01:41 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 13:22:44 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "cub.h"

int		key_w(t_params *p);
int		key_a(t_params *p);
int		key_s(t_params *p);
int		key_d(t_params *p);
int		key_a_l(t_params *p);
int		key_a_r(t_params *p);

int		key_press(int keycode, void *pr);
int		key_release(int keycode, void *pr);

#endif
