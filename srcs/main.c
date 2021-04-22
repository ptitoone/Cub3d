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
#include "parse.h"
#include "utils.h"
#include "errors.h"
#include "controls.h"

static int	render(void *pr)
{
	t_params	*p;

	p = (t_params *)pr;
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
	render_frame(p);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_params	p;

	p.player.start_dir = -1;
	p.mlx = mlx_init();
	if (p.mlx == NULL)
		return (throw_error(ERR_MLX_FAIL));
	if (!check_errors(argv[1]))
		return (free_params(&p));
	if (!(parse_file(argv[1], &p)))
		return (free_params(&p));
	if (!(lay_map(argv[1], &p)))
		return (free_params(&p));
	if (!(init_tex_img(&p)))
		return (free_params(&p));
	init_sprites(&p);
//	if (!(check_map_validity(p.map.map, p.map.map_h)))
//		return (0);
	if (!(init_params(&p)))
		return (free_params(&p));
	mlx_hook(p.win, 2, 1L << 0, &key_press, (void *)&p);
	mlx_hook(p.win, 3, 1L << 1, &key_release, (void *)&p);
	mlx_loop_hook(p.mlx, &render, (void *)&p);
	mlx_loop(p.mlx);
	return (0);
}
