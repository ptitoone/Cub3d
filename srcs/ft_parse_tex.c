/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:03:04 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/16 11:26:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_add_tex(char *l, char **dst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*dst)
	{
		while (l[i] == ' ')
			i++;
		if (!l[i])
		{
			printf("Error : %s\n", ERR_TEX_NULL);
			return (0);
		}
		while (l[i + j] != ' ' && l[i + j] != 0)
			j++;
		*dst = ft_substr(l, i, j);
		if (*dst)
			return (1);
	}
	else
		printf("Error : %s\n", ERR_TEX_DUP);
	return (0);
}

int	ft_parse_tex(char *l, t_tex *t)
{
	int i;

	i = 0;
	while (l[i] == ' ' && l[i] != 0)
		i++;
	if (l[i] == 'N' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (ft_add_tex(&l[i + 2], &t->dir[NO]));
	else if (l[i] == 'S' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (ft_add_tex(&l[i + 2], &t->dir[SO]));
	else if (l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		return (ft_add_tex(&l[i + 2], &t->dir[WE]));
	else if (l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		return (ft_add_tex(&l[i + 2], &t->dir[EA]));
	else if (l[i] == 'S' && l[i + 1] == ' ')
		return (ft_add_tex(&l[i + 1], &t->sp));
	else if (l[i] == 'F' && l[i + 1] == ' ')
		return (ft_add_tex(&l[i + 1], &t->f));
	else if (l[i] == 'C' && l[i + 1] == ' ')
		return(ft_add_tex(&l[i + 1], &t->c));
	else
		printf("Error : %s \"%s\"\n", ERR_TEX_INV, l);
	return (0);
}
