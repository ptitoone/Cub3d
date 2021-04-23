/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:05 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:04:38 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "throw_error.h"
#include "parse.h"

static int	push_res(char *l, int i, int j)
{
	char	*tmp;
	int		res;

	tmp = ft_substr(l, i, j);
	if (tmp)
	{
		res = ft_atoi(tmp);
		free(tmp);
		return (res);
	}
	return (throw_error(ERR_MALLOC_FAIL));
}

static int	add_res(char *l, t_params *p)
{
	t_counter	c;

	c.i = 0;
	c.count = -1;
	while (++c.count < 2)
	{
		c.j = 0;
		while (l[c.i] == ' ')
			if (!l[c.i++] || !(l[c.i] >= '1' && l[c.i] <= '9'))
				return (0);
		if (l[c.i] >= '1' && l[c.i] <= '9')
			c.j++;
		while (l[c.i + c.j] >= '0' && l[c.i + c.j] <= '9')
			c.j++;
		if (!(c.count % 2))
			p->win_w = push_res(l, c.i, c.j + 1);
		else
			p->win_h = push_res(l, c.i, c.j-- + 1);
		c.i += (c.j + 1);
	}
	while (l[c.i] == ' ')
		c.i++;
	if (!l[c.i])
		return (1);
	return (0);
}

int	parse_res(char *l, t_params *p)
{
	int	i;

	i = 0;
	if (p->win_h != 0 && p->win_w != 0)
		return (throw_error(ERR_RES_DUP));
	while (l[i] == ' ')
		i++;
	if (l[i] == 'R' && l[i + 1] == ' ')
		if (add_res(&l[i + 1], p))
			return (1);
	return (throw_error(ERR_RES_INV));
}
