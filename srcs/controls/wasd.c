#include "cub.h"
#include "controls.h"

int	key_w(t_params *p)
{
	int	x_os;
	int	y_os;

	x_os = p->player.pos_x + p->player.del_x * 7;
	y_os = p->player.pos_y + p->player.del_y * 7;
	if (p->map.map[y_os / C_S][x_os / C_S] == '0')
	{
		p->player.pos_x += (2 * p->player.del_x);
		p->player.pos_y += (2 * p->player.del_y);
	}
	return (0);
}

int	key_s(t_params *p)
{
	int	x_os;
	int	y_os;

	x_os = p->player.pos_x - p->player.del_x * 7;
	y_os = p->player.pos_y - p->player.del_y * 7;
	if (p->map.map[y_os / C_S][x_os / C_S] == '0')
	{
		p->player.pos_x -= (2 * p->player.del_x);
		p->player.pos_y -= (2 * p->player.del_y);
	}
	return (0);
}

int	key_a(t_params *p)
{
	int	x_os;
	int	y_os;

	x_os = p->player.pos_x + p->player.strafe_del_x * 7;
	y_os = p->player.pos_y + p->player.strafe_del_y * 7;
	if (p->map.map[y_os / C_S][x_os / C_S] == '0')
	{
		p->player.pos_x += (2 * p->player.strafe_del_x);
		p->player.pos_y += (2 * p->player.strafe_del_y);
	}
	return (0);
}

int	key_d(t_params *p)
{
	int	x_os;
	int	y_os;

	x_os = p->player.pos_x - p->player.strafe_del_x * 7;
	y_os = p->player.pos_y - p->player.strafe_del_y * 7;
	if (p->map.map[y_os / C_S][x_os / C_S] == '0')
	{
		p->player.pos_x -= (2 * p->player.strafe_del_x);
		p->player.pos_y -= (2 * p->player.strafe_del_y);
	}
	return (0);
}
