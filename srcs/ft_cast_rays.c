/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:57:28 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/29 17:28:06 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_draw_line(int rc, double ra, double x, double y, t_params *p, int color)
{
	int i;
	int j;
	double dist;
	int wall_h;

//////// TEXTURE TEST ////////////////////////////////////////////////

	char tex[16][16] = 	{{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
						{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','1','1','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','1','1','1','1','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','1','1','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1'},
						{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
						{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};

/////////////////////////////////////////////////////////////////////

	i = 0;
	j = 0;
	dist = sqrt(((p->player.pos_x - x) * (p->player.pos_x - x)) + ((p->player.pos_y - y) * (p->player.pos_y - y)));
	dist = dist * cos(p->player.orient - ra);
	wall_h = (int)floor(((p->map.block_w  * p->win_h) / dist) / p->ratio);
	if (wall_h * 2 > p->win_h)
		wall_h = p->win_h / 2;
	while (i++ < (p->win_h / 2) - wall_h)
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x002E4172);
	i = 0;
	while (i++ < 16)
		ft_draw_tex_col(tex, rc, i + 45, p->win_h / 16, &p->imgv);
//	my_mlx_pixel_put(&p->imgv, rc, j++, color);
	i = 0;
	while (i++ < ((p->win_h / 2) - wall_h))
		my_mlx_pixel_put(&p->imgv, rc, j++, 0x00353D4E);
}

static void	ft_clear_img(t_params *p)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < p->win_w)
	{
		y = 0;
		while (y < p->win_h)
			my_mlx_pixel_put(&p->imgv, x, y++, 0x00000000);
		x++;
	}
}

static int ft_check_hori_lines(t_params *p, double ra, t_coords *point)
{
	double 	xo;
	double 	yo;
	double 	itan;
	int		dof;

	dof = 100;
	itan  = -1 / tan(ra);
	point->x = p->player.pos_x;
	point->y = p->player.pos_y;
	if (ra > PI)
	{
		point->y = floor(p->player.pos_y / p->map.block_w ) * (p->map.block_w ) - 0.0005;
		point->x = (p->player.pos_y - point->y) * itan + p->player.pos_x ;
		yo = -p->map.block_w ;
		xo = -yo * itan;
		dof = 0;
	}
	if (ra < PI)
	{
		point->y = floor(p->player.pos_y / p->map.block_w ) * (p->map.block_w ) + p->map.block_w;
		point->x = (p->player.pos_y - point->y) * itan + p->player.pos_x ;
		yo = p->map.block_w ;
		xo = -yo * itan;
		dof = 0;
	}
	while (dof++ < 100)
	{
		if (point->x >= 0 && point->x <= p->map.map_w*p->map.block_w  && point->y >= 0 && point->y <= p->map.map_h*p->map.block_w )
			if (p->map.map[(int)point->y/p->map.block_w ][(int)point->x/p->map.block_w ] == '1')
			//	ft_plot_line(p->player.pos_x, p->player.pos_y, point->x, point->y, 0x00000000, p);
				return (1);
		point->x+=xo;
		point->y+=yo;
	}
	return (0);
}

static int	ft_check_vert_lines(t_params *p, double ra, t_coords *point)
{
	double 	xo;
	double 	yo;
	double 	ntan;
	int		dof;

	dof = 100;
	ntan = -tan(ra);
	point->x = p->player.pos_x;
	point->y = p->player.pos_y;
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		point->x = floor(p->player.pos_x / p->map.block_w ) * (p->map.block_w ) - 0.0005;
		point->y = (p->player.pos_x - point->x) * ntan + p->player.pos_y ;
		xo = -p->map.block_w ;
		yo = -xo * ntan;
		dof = 0;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		point->x = floor(p->player.pos_x / p->map.block_w ) * (p->map.block_w ) + p->map.block_w;
		point->y = (p->player.pos_x - point->x) * ntan + p->player.pos_y ;
		xo = p->map.block_w ;
		yo = -xo * ntan;
		dof = 0;
	}
	while (dof++ < 100)
	{
		if (point->x >= 0 && point->x <= p->map.map_w*p->map.block_w  && point->y >= 0 && point->y <= p->map.map_h*p->map.block_w )
			if (p->map.map[(int)point->y/p->map.block_w ][(int)point->x/p->map.block_w ] == '1')
 			//	ft_plot_line(p->player.pos_x, p->player.pos_y, point->x, point->y, 0x0000FF00, p);
				return (1);
		point->x+=xo;
		point->y+=yo;
	}
	return (0);
}

int ft_find_wall(t_params *p)
{
	int 	i;
	double	ra;
	t_coords h;
	t_coords v;

	h.x = 0; h.y = 0;
	v.x = 0; v.y = 0;

	i = -1;
	ra = p->player.orient - (30 * PI / 180);
	ft_clear_img(p);
	while(i++ < p->win_w - 1)
	{
		if (ra < 0)
			ra +=2*PI;
		if (ra > 2*PI)
			ra -=2*PI;
		ft_check_hori_lines(p, ra, &h);
		ft_check_vert_lines(p, ra, &v);
		if (sqrt(pow(h.x - p->player.pos_x, 2) + pow(h.y - p->player.pos_y, 2)) <= 
			sqrt(pow(v.x - p->player.pos_x, 2) + pow(v.y - p->player.pos_y, 2)))
			ft_draw_line(i, ra, h.x-1, h.y-1, p, 0x00F17600);
		else
			ft_draw_line(i, ra, v.x, v.y, p, 0x00954900);
		ra += ((60 * PI / 180) / p->win_w);
	}
	mlx_put_image_to_window(p->mlx, p->win2, p->imgv.img, 0, 0);
	return (0);
}

