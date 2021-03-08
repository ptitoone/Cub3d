#include "mlx.h"
#include <stdio.h>

typedef struct 	s_params
{

	void *mlx;
	void *win;

}				t_params;

int mouse(int button, int x, int y, void *pr)
{
	t_params *p;
	int pix;
	int pix2;
	int z;
	int w;

	pix  = 10;
	pix2 = 10;
	x = x - 5;
	y = y - 5;
	z = x;
	w = y;
	p = (t_params *)pr;
	if (button == 1)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0050050050);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	if (button == 2)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0150150150);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	if (button == 5)
	{
		while (pix-- > 0)
		{
			while (pix2-- > 0)
			{
				mlx_pixel_put(p->mlx, p->win, z++, w , 0070010070);
			}
			w++;
			pix2 = 10;
			z = x;
		}
	}
	return (0);
}

int	draw_down(int keycode, void *pr)
{
	static int x;
	static int y;
	int pix;

	pix = 17;
	t_params *p;

	p = (t_params *)pr;
	if (keycode == 1)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, x, y++, 0150150150);
	if (keycode == 13)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, x, y--, 0150150150);
	if (keycode == 0)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, x--, y, 0150150150);
	if (keycode == 2)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, x++, y, 0150150150);
	return (0);
}

int main()
{
	t_params	p;
	int 		x;
	int			y;
	int			(*fnc)(int keycode, void *);
	int			(*fnc2)(int button, int x, int y, void *);

	p.mlx = mlx_init();
	x = 0;
	y = 0;
	fnc = &draw_down;
	fnc2 = &mouse;
	if (p.mlx == NULL)
		puts("error");
	p.win = mlx_new_window(p.mlx, 640, 640, "My Window");
	mlx_clear_window(p.mlx, p.win);
	while (x < 640)
	{
		while (y < 640)
		{
			mlx_pixel_put(p.mlx, p.win, y, x, 0100100100);
			y++;
		}
		y = 0;
		x += 16;
	}
	mlx_mouse_hook(p.win, fnc2, (void *)&p);
	mlx_key_hook(p.win, fnc, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
