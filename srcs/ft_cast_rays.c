/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/17 16:24:32 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_draw_line(int rc, float ra, float x, float y, t_params *p)
{
	int i;
	int j;
	float dist;
	int wall_h;
	float tmp;

	i = 0;
	j = 0;
	tmp = ((p->player.pos_x - x) * (p->player.pos_x - x)) + ((p->player.pos_y - y) * (p->player.pos_y - y));
	dist = sqrtf(tmp);
	dist = dist * (cos(p->player.orient - ra));
	wall_h = (int)floor((C_H * p->win_h) / dist);
	if (wall_h * 2 > p->win_h)
		wall_h = p->win_h / 2;
	//ceil white
	while (i < ((C_H / 2) * p->map.map_h - wall_h))
	{
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x002E4172);
		i++;
	}
	i = 0;
	//wall red
	while (i < wall_h)
	{
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00F17600);
		i++;
	}
	i = 0;
	while (i < wall_h)
	{
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00F17600);
		i++;
	}

	i = 0;
	//floor green
	while (i < ((C_H / 2) * p->map.map_h - wall_h))
	{
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00353D4E);
		i++;
	}
}

static void	ft_clear_img(t_params *p)
{
	int x = 0;
	int y = 0;

	while (x < p->win_w)
	{
		y = 0;
		while (y < p->win_h)
			my_mlx_pixel_put(&p->imgv, x, y++, 0x00000000);
		x++;
	}
}

int ft_find_wall(t_params *p)
{
	float 	ra;
	float 	rx;
	float 	ry;
	float 	xo;
	float 	yo;
	float 	itan;
	float 	ntan;

	int dof = 0;

	ra = p->player.orient;
	ntan  = -tan(ra);
	/*if (ra > PI / 2 && ra < 3 * PI / 2)
	{
		rx = floor(p->player.pos_x / 64) * (64) - 1;
		ry = (p->player.pos_x - rx) * ntan + p->player.pos_y ;
		xo = -64;
		yo = -xo * ntan;
	}
	if (ra < PI / 2 || ra > 3 * PI / 2)
	{
		rx = floor(p->player.pos_x / 64) * (64) + 64;
		ry = (p->player.pos_x - rx) * ntan + p->player.pos_y ;
		xo = 64;
		yo = -xo * ntan;
	}
	if (ra == 0 || ra == PI)
	{
		rx = p->player.pos_x;
		ry = p->player.pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		printf("map[%i][%i] = %c\n", (int)ry/64, (int)rx/64, p->map.map[(int)ry/64][(int)rx/64]);
		if (p->map.map[(int)ry/64][(int)rx/64] == '1')
			break ;
		rx+=xo; ry+=yo;
	}
 	ft_plot_line(p->player.pos_x, p->player.pos_y, rx, ry, 0x0000FF00, p);
	*/itan  = -1 / tan(ra);
	if (ra > PI)
	{
		ry = floor(p->player.pos_y / 64) * (64) - 1;
		rx = (p->player.pos_y - ry) * itan + p->player.pos_x ;
		yo = -64;
		xo = -yo * itan;
	}
	if (ra < PI)
	{
		ry = floor(p->player.pos_y / 64) * (64) + 64;
		rx = (p->player.pos_y - ry) * itan + p->player.pos_x ;
		yo = 64;
		xo = -yo * itan;
	}
	if (ra == 0 || ra == PI)
	{
		rx = p->player.pos_x;
		ry = p->player.pos_y;
		dof = 8;
	}
	while (dof < 8)
	{
		//printf("map[%i][%i] = %c", (int)ry/64, (int)rx/64, p->map.map[(int)ry/64][(int)rx/64]);
		if (p->map.map[(int)ry/64][(int)rx/64] == '1')
			break ;
		rx+=xo;
		ry+=yo;
	}
 	ft_plot_line(p->player.pos_x, p->player.pos_y, rx, ry, 0x0000FFFF, p);
}

/*
int	ft_find_wall(t_params *p)
{
	float x1;
	float y1;
	float xo;
	float yo;
	int i, z, b; 
	float ra = p->player.orient - (30 * PI / 180);

	i = -1;
//	ft_clear_img(p);
	while(i++ < C_H*p->map.map_w)
	{
		xo = p->player.pos_x;
		yo = p->player.pos_y;
		x1 = cos(ra) / C_H;
		y1 = sin(ra) / C_H;
		while (1)
		{
			xo += x1;
			yo += y1;
			z =(int)floor(xo);
			b =(int)floor(yo);
			if (p->map.map[b/C_H][z/C_H] == '1')
				break ;
		}
 		ft_plot_line(p->player.pos_x, p->player.pos_y, z, b, 0x0000FF00, p);
		ra += ((60 * PI / 180) / p->win_w);
//		ft_draw_line(i, ra, xo, yo, p);
	}
//	mlx_put_image_to_window(p->mlx, p->win2, p->imgv.img, 0, 0);
	return (0);
}*/
