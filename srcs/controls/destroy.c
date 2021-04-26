/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:34:06 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 13:23:23 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "controls.h"
#include "utils.h"

int	destroy(void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
	free_params(p);
	exit(EXIT_SUCCESS);
}
