/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:30:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/10 15:26:31 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_tex(t_params *p)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (p->tex.type[i].path != NULL)
			free(p->tex.type[i].path);
		if (p->tex.type[i].img.img != NULL)
			mlx_destroy_image(p->mlx, p->tex.type[i].img.img);
		i++;
	}
	if (p->tex.f != NULL)
		free(p->tex.f);
	if (p->tex.c != NULL)
		free(p->tex.c);
}

static void	free_map(t_params *p)
{
	int	y;

	y = 0;
	if (p->map.map != NULL)
	{
		while (y < p->map.map_h)
		{
			free(p->map.map[y]);
			y++;
		}
		free(p->map.map);
	}
}

int	free_params(t_params *p)
{
	if (p->win != NULL)
		mlx_destroy_window(p->mlx, p->win);
	if (p->frame.img != NULL)
		mlx_destroy_image(p->mlx, p->frame.img);
	free_map(p);
	free_tex(p);
	return (0);
}
