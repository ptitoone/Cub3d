/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:05 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/06 16:11:47 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ft_map.h"

static int	ft_add_res(char *l, t_params *p)
{
	int i;
	int j;
	int x;
	char *tmp;

	i = 0;
	x = -1;
	while (++x < 2)
	{
		j = 0;
		if (!l[i])
			return(puts(ERR_RES_INV));
		while (l[i] == ' ')
			i++;
		if (l[i] >= '1' && l[i] <= '9')
			j++;
		while (l[i + j] >= '0' && l[i + j] <= '9')
			j++;
		tmp = ft_substr(l, i ,j + 1);
		if (!(x % 2))
			p->win_w = ft_atoi(tmp);
		else
			p->win_h = ft_atoi(tmp);
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		i += (j + 1);
	}
	if (!l[i + j + 1])
		return (1);
	return (0);
}

int	ft_parse_res(char *l, t_params *p)
{
	int i;

	i = 0;
	while (l[i] == ' ' && l[i] != 0)
		i++;
	if (l[i] == 'R' && l[i + 1] == ' ')
		if (ft_add_res(&l[i + 1], p))
			return (1);
	return (puts(ERR_RES_NF));
}
