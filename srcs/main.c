/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:59 by akotzky           #+#    #+#             */
/*   Updated: 2021/04/07 15:37:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ft_parse.h"
#include "controls.h"

static int	render(void *pr)
{
	t_params *p = (t_params *)pr;
	if (p->keys.w == 1)
		key_w(p);
	if (p->keys.a == 1)
		key_a(p);
	if (p->keys.s == 1)
		key_s(p);
	if (p->keys.d == 1)
		key_d(p);
	if (p->keys.l == 1)
		key_a_l(p);
	if (p->keys.r == 1)
		key_a_r(p);
	ft_find_wall(p);
	return (0);
}

int main()
{
	static t_params	p;
//////// PARAMS SETUP /////////////////////////////////////////////////////////

	if(!(ft_parse_file("map.cub", &p)))
		return (0);
	ft_init_params(&p);
	p.player.pos_x	=	(p.map.c_s * p.map.map_w) / 2;
	p.player.pos_y	=	(p.map.c_s * p.map.map_h) / 2;
	if (!(ft_init_tex_img(&p)))
		return (0);

///////// CREATE IMAGES ///////////////////////////////////////////////////////

//	p.img.img	= 	mlx_new_image(p.mlx, (p.win_w), (p.win_h));
//	p.img.addr	= 	mlx_get_data_addr(p.img.img, &p.img.bpp, 
//					&p.img.line_len, &p.img.endian);

///////// CREATE WINDOWS //////////////////////////////////////////////////////

//	p.win		=	mlx_new_window(p.mlx, (p.win_w), (p.win_h), "Map");

//////// TEST UPSCALE IMG /////////////////////////////////////////////////////

//	int img_w = 0;
//	int img_h = 0;
//	t_img img_x;
//	t_img img_up;
//
//	img_x.img	=	mlx_xpm_file_to_image(p.mlx, "./hud.xpm", &img_w, &img_h);
//	img_x.addr	=	mlx_get_data_addr(img_x.img, &img_x.bpp,
//					&img_x.line_len, &img_x.endian);
//	img_up.img	=	mlx_new_image(p.mlx, (img_w * 11), (img_h * 11));
//	img_up.addr	=	mlx_get_data_addr(img_up.img, &img_up.bpp,
//					&img_up.line_len, &img_up.endian);
//	ft_upscale_img(img_w, img_h, 11, img_x.addr, img_up.addr);
//	mlx_put_image_to_window(p.mlx, p.win2, img_up.img, 0, 0);

///////// DRAW AND PUT IMAGES TO WINDIOWS //////////////////////////////////////

//	ft_draw_map(&p);
//	ft_draw_player(p.player.pos_x, p.player.pos_y, &p);
//	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);

///////// HOOKS AND LOOP //////////////////////////////////////////////////////
	mlx_hook(p.win2, 2, 1L<<0, &key_press, (void *)&p);
	mlx_hook(p.win2, 3, 1L<<1, &key_release, (void *)&p);
//	mlx_hook(p.win2, 6, 1L<<6, mouse, (void *)&p);
	mlx_loop_hook(p.mlx, &render, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
