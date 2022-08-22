#include "cub.h"

int	key_a_l(t_params *p)
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
	return (0);
}

int	key_a_r(t_params *p)
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
	return (0);
}
