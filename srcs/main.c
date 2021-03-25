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

int main()
{
	int			(*k)(int keycode, void *);
	int			(*m)(int button, int x, int y, void *);
	t_params	p;

	k = &ft_keys;
	m = &ft_mouse;
	// Params set up // 
	ft_init_params(&p);
	ft_parse_map("map.cub", &p);
	p.map.block_w = p.win_w / 16;
	p.player.pos_x = (p.map.map_w * p.map.block_w) / 2;
	p.player.pos_y = (p.map.map_h * p.map.block_h) / 2;
	p.ratio = p.win_w / p.win_h;
	p.mlx = mlx_init();
	if (p.mlx == NULL)
		puts("error");
//	p.win = mlx_new_window(p.mlx, (p.win_w), (p.win_h), "Map");
	p.win2 = mlx_new_window(p.mlx, (p.win_w), (p.win_h), "FPV");
//	p.img.img = mlx_new_image(p.mlx, (p.win_w), (p.win_h));
//	p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bpp, &p.img.line_len, &p.img.endian);
	p.imgv.img = mlx_new_image(p.mlx, (p.win_w), (p.win_h));
	p.imgv.addr = mlx_get_data_addr(p.imgv.img, &p.imgv.bpp, &p.imgv.line_len, &p.imgv.endian);
	/////////////////////
//	ft_draw_map(&p);
//	ft_draw_player(p.player.pos_x, p.player.pos_y, &p);
//	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
//	mlx_mouse_hook(p.win, m, (void *)&p);
	mlx_hook(p.win2, 2, 1L<<0, k, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
