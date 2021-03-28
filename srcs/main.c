/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:59 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/25 12:47:41 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ft_map.h"
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

static int	ft_key_w(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x + p->player.del_x;
	y_offset = p->player.pos_y + p->player.del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x += (2 * p->player.del_x);
		p->player.pos_y += (2 * p->player.del_y);
	}
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_s(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x - p->player.del_x;
	y_offset = p->player.pos_y - p->player.del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x -= (2 * p->player.del_x);
		p->player.pos_y -= (2 * p->player.del_y);
	}
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_a_l(t_params *p)
{
	p->player.orient -= 0.05;
	p->player.strafe_orient -= 0.05;
	if (p->player.orient < 0)
		p->player.orient += (2 * PI);
	if (p->player.strafe_orient < 0)
		p->player.strafe_orient += (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	p->player.strafe_del_x = cos(p->player.strafe_orient) * 5;
	p->player.strafe_del_y = sin(p->player.strafe_orient) * 5;
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_a_r(t_params *p)
{
	p->player.orient += 0.05;
	p->player.strafe_orient += 0.05;
	if (p->player.orient > (2 * PI))
		p->player.orient -= (2 * PI);
	if (p->player.strafe_orient > (2 * PI))
		p->player.strafe_orient -= (2 * PI);
	p->player.del_x = cos(p->player.orient) * 5;
	p->player.del_y = sin(p->player.orient) * 5;
	p->player.strafe_del_x = cos(p->player.strafe_orient) * 5;
	p->player.strafe_del_y = sin(p->player.strafe_orient) * 5;
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_a(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x + p->player.strafe_del_x;
	y_offset = p->player.pos_y + p->player.strafe_del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x += (2 * p->player.strafe_del_x);
		p->player.pos_y += (2 * p->player.strafe_del_y);
	}
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

static int	ft_key_d(t_params *p)
{
	int x_offset;
	int y_offset;

	x_offset = p->player.pos_x - p->player.strafe_del_x;
	y_offset = p->player.pos_y - p->player.strafe_del_y;
	if (p->map.map[y_offset/p->map.block_w][x_offset/p->map.block_w] != '1')
	{
		p->player.pos_x -= (2 * p->player.strafe_del_x);
		p->player.pos_y -= (2 * p->player.strafe_del_y);
	}
//	ft_draw_map(p);
//	ft_draw_player(p->player.pos_x, p->player.pos_y, p);
//	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

int	ft_render(void *pr)
{
	t_params *p = (t_params *)pr;
	if (p->keys.w == 1)
		ft_key_w(p);
	if (p->keys.a == 1)
		ft_key_a(p);
	if (p->keys.s == 1)
		ft_key_s(p);
	if (p->keys.d == 1)
		ft_key_d(p);
	if (p->keys.l == 1)
		ft_key_a_l(p);
	if (p->keys.r == 1)
		ft_key_a_r(p);
	ft_find_wall(p);
	return (0);
}

int main()
{
	int			(*keys)(int keycode, void *);
	int			(*keysr)(int keycode, void *);
	int			(*mouse)(int x, int y, void *pr);
	int			(*render)(void *pr);
	t_params	p;

	keys	=	&ft_keys;
	keysr	=	&ft_keysr;
	mouse	=	&ft_mouse;
	render	=	&ft_render;

//////// PARAMS SETUP /////////////////////////////////////////////////////////

	ft_init_params(&p);
	ft_init_keys(&p.keys);
	ft_parse_map("map.cub", &p);

	p.map.block_w	=	p.win_w / 16;
	p.player.pos_x	=	(p.map.block_w * 2) / 2;
	p.player.pos_y	=	(p.map.block_w * 6) / 2;
	p.ratio			=	p.win_w / p.win_h;
	p.mlx			=	mlx_init();

	if (p.mlx == NULL)
		puts("Error");

///////// CREATE FIRS VIEW IMAGE //////////////////////////////////////////////

//	p.img.img	= 	mlx_new_image(p.mlx, (p.win_w), (p.win_h));
//	p.img.addr	= 	mlx_get_data_addr(p.img.img, &p.img.bpp, 
//					&p.img.line_len, &p.img.endian);
	p.imgv.img	= 	mlx_new_image(p.mlx, (p.win_w), (p.win_h));
	p.imgv.addr	= 	mlx_get_data_addr(p.imgv.img, &p.imgv.bpp,
					&p.imgv.line_len, &p.imgv.endian);

///////// CREATE WINDOWS //////////////////////////////////////////////////////

//	p.win		=	mlx_new_window(p.mlx, (p.win_w), (p.win_h), "Map");
	p.win2		=	mlx_new_window(p.mlx, (p.win_w), (p.win_h), "FPV");

//////// TEST UPSCALE IMG /////////////////////////////////////////////////////

	int img_w = 0;
	int img_h = 0;
	t_img img_x;
	t_img img_up;

	img_x.img	=	mlx_xpm_file_to_image(p.mlx, "./hud.xpm", &img_w, &img_h);
	img_x.addr	=	mlx_get_data_addr(img_x.img, &img_x.bpp,
					&img_x.line_len, &img_x.endian);
	img_up.img	=	mlx_new_image(p.mlx, (img_w * 11), (img_h * 11));
	img_up.addr	=	mlx_get_data_addr(img_up.img, &img_up.bpp,
					&img_up.line_len, &img_up.endian);
	ft_upscale_img(img_w, img_h, 11, img_x.addr, img_up.addr);
	mlx_put_image_to_window(p.mlx, p.win2, img_up.img, 0, 0);

///////// DRAW AND PUT IMAGES TO WINDIOWS //////////////////////////////////////

//	ft_draw_map(&p);
//	ft_draw_player(p.player.pos_x, p.player.pos_y, &p);
//	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
//	mlx_mouse_hook(p.win2, mouse, (void *)&p);

///////// HOOKS AND LOOP //////////////////////////////////////////////////////
	mlx_hook(p.win2, 2, 1L<<0, keys, (void *)&p);
	mlx_hook(p.win2, 3, 1L<<1, keysr, (void *)&p);
	mlx_hook(p.win2, 6, 1L<<6, mouse, (void *)&p);
	mlx_loop_hook(p.mlx, render, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
