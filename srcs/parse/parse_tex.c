/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:03:04 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "throw_error.h"

static int	add_tex(char *l, char **dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*dst)
	{
		while (l[i] == ' ')
			i++;
		if (!l[i])
			return (throw_error(ERR_TEX_NULL));
		while (l[i + j] != ' ' && l[i + j] != 0)
			j++;
		*dst = ft_substr(l, i, j);
		if (*dst)
			return (1);
	}
	return (throw_error(ERR_TEX_DUP));
}

int	parse_tex(char *l, t_params *p)
{
	int	i;

	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] == 'N' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (add_tex(&l[i + 2], &p->tex.type[NO].path));
	else if (l[i] == 'S' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (add_tex(&l[i + 2], &p->tex.type[SO].path));
	else if (l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		return (add_tex(&l[i + 2], &p->tex.type[WE].path));
	else if (l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		return (add_tex(&l[i + 2], &p->tex.type[EA].path));
	else if (l[i] == 'S' && l[i + 1] == ' ')
		return (add_tex(&l[i + 1], &p->tex.type[S1].path));
	else if (l[i] == 'F' && l[i + 1] == ' ')
		return (add_tex(&l[i + 1], &p->tex.f));
	else if (l[i] == 'C' && l[i + 1] == ' ')
		return (add_tex(&l[i + 1], &p->tex.c));
	else
		return (0);
}
