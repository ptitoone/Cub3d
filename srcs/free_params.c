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

static void free_tex(t_params *p)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (p->tex.dir[i] != NULL)
			free(p->tex.dir[i]);
		i++;
	}
	if (p->tex.sp != NULL)
		free(p->tex.sp);
	if (p->tex.f != NULL)
		free(p->tex.f);
	if (p->tex.c != NULL)
		free(p->tex.c);
	if (p->tex.no.img != NULL)
		mlx_destroy_image(p->mlx, p->tex.no.img);
	if (p->tex.so.img != NULL)
		mlx_destroy_image(p->mlx, p->tex.so.img);
	if (p->tex.we.img != NULL)
		mlx_destroy_image(p->mlx, p->tex.we.img);
	if (p->tex.ea.img != NULL)
		mlx_destroy_image(p->mlx, p->tex.ea.img);
}

static void free_map(t_params *p)
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

int free_params(t_params *p)
{
	if (p->win != NULL)
		mlx_clear_window(p->mlx, p->win);
	if (p->win2 != NULL)
		mlx_clear_window(p->mlx, p->win2);
	if (p->img.img != NULL)
		mlx_destroy_image(p->mlx, p->img.img);
	if (p->imgv.img != NULL)
		mlx_destroy_image(p->mlx, p->imgv.img);
	free_map(p);
	free_tex(p);
	return (0);
}

