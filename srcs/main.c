/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:59 by akotzky           #+#    #+#             */
/*   Updated: 2021/03/17 11:31:03 by akotzky          ###   ########.fr       */
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
	int test_w;
	int test_h;


	ft_init_params(&p);
	k = &ft_keys;
	m = &ft_mouse;
	ft_parse_map("map.cub", &p);

	p.mlx = mlx_init();
	if (p.mlx == NULL)
		puts("error");
	printf("Map w = %i Map h = %i", p.map.map_w, p.map.map_h);
	p.win = mlx_new_window(p.mlx, (C_H * p.map.map_w), (C_H * p.map.map_h), "Map");
	p.win2 = mlx_new_window(p.mlx, (C_H * p.map.map_w), (C_H * p.map.map_h), "FPV");
	p.img.img = mlx_new_image(p.mlx, (C_H * p.map.map_w), (C_H * p.map.map_h));
	p.img.addr = mlx_get_data_addr(p.img.img, &p.img.bpp, &p.img.line_len, &p.img.endian);

	p.imgv.img = mlx_new_image(p.mlx, (C_H * p.map.map_w), (C_H * p.map.map_h));
	p.imgv.addr = mlx_get_data_addr(p.imgv.img, &p.imgv.bpp, &p.imgv.line_len, &p.imgv.endian);
	ft_draw_map(&p);
	ft_draw_player(p.player.pos_x, p.player.pos_y, &p);
	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
	mlx_mouse_hook(p.win, m, (void *)&p);
	mlx_hook(p.win, 2, 1L<<0, k, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
