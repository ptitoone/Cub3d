#include "incls/cub.h"

void	ft_init_params(t_params *p)
{
	int i;

	i = -1;
	p->mlx = NULL;
	p->win = NULL;
	p->win_w = 0;
	p->win_h = 0;
	while (i++ < 4)
		p->tex.dir[i] = NULL;
	p->tex.sp = NULL;
	p->tex.f = NULL;
	p->tex.c = NULL;
	p->player.pos_x = 0;
	p->player.pos_y = 0;
	p->player.orient = 0;
	p->map.map_w = 0;
	p->map.map_h = 0;
	p->map.map = NULL;
	p->img.img = NULL;
	p->img.addr = NULL;
	p->img.bpp = 0;
	p->img.line_len = 0;
	p->img.endian = 0;
}
