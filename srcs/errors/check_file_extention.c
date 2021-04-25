/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extention.c								:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:37:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:00:58 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	check_file_extention(const char *file_name)
{
	int	i;

	while (file_name[i])
		i++;
	if (file_name[--i] == 'b')
		if (file_name[--i] == 'u')
			if (file_name[--i] == 'c')
				if (file_name[--i] == '.')
					return (1);
	return (throw_error(ERR_FILE_EXT_INV));
}
