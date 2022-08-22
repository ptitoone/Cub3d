#include "cub.h"
#include "parse.h"
#include "engine.h"

static int	check_wall_hit(t_coords *c, t_params *p, double x_os, double y_os)
{
	int	dof;

	dof = 0;
	while (dof++ < 100)
	{
		if (c->y / C_S >= p->map.map_h)
			c->y -= 0.0000005;
		if (c->x >= 0
			&& c->x <= p->map.map_w * C_S
			&& c->y >= 0
			&& c->y <= p->map.map_h * C_S)
		{
			if (is_sprite_spec(p->map.map[(int)c->y / C_S][(int)c->x / C_S]))
				set_sprite_visible(&p->s_data,
					(int)c->x / C_S, (int)c->y / C_S);
			if (p->map.map[(int)c->y / C_S][(int)c->x / C_S] == '1')
				return (1);
		}
		c->x += x_os;
		c->y += y_os;
	}
	return (0);
}

static int	check_hori_lines(t_params *p, double ra, t_coords *c)
{
	double	x_os;
	double	y_os;
	double	inv_tan;

	inv_tan = -1 / tan(ra);
	if (ra == 0 || ra == PI)
		return (0);
	if (ra > PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S - 0.0005;
		c->x = (p->player.pos_y - c->y) * inv_tan + p->player.pos_x;
		y_os = -C_S ;
		x_os = -y_os * inv_tan;
	}
	if (ra < PI)
	{
		c->y = floor(p->player.pos_y / C_S) * C_S + C_S;
		c->x = (p->player.pos_y - c->y) * inv_tan + p->player.pos_x;
		y_os = C_S ;
		x_os = -y_os * inv_tan;
	}
	if (check_wall_hit(c, p, x_os, y_os))
		return (1);
	return (0);
}

static int	check_vert_lines(t_params *p, double ra, t_coords *c)
{
	double	x_os;
	double	y_os;
	double	neg_tan;

	neg_tan = -tan(ra);
	if (ra == PI / 2 || ra == 3 * PI / 2)
		return (0);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S - 0.0005;
		c->y = (p->player.pos_x - c->x) * neg_tan + p->player.pos_y - 0.0000005;
		x_os = -C_S;
		y_os = -x_os * neg_tan;
	}
	if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		c->x = floor(p->player.pos_x / C_S) * C_S + C_S;
		c->y = (p->player.pos_x - c->x) * neg_tan + p->player.pos_y - 0.0000005;
		x_os = C_S;
		y_os = -x_os * neg_tan;
	}
	if (check_wall_hit(c, p, x_os, y_os))
		return (1);
	return (0);
}

void	check_lines(t_params *p, double ra, t_coords *h, t_coords *v)
{
	check_vert_lines(p, ra, v);
	check_hori_lines(p, ra, h);
}
