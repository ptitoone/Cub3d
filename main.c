#include "incls/cub.h"
#include "incls/ft_map.h"

int posx = 0;
int posy = 0;

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
	if (button == M_l)
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
	if (button == M_r)
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
	if (button == M_u)
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

int	move(int keycode, void *pr)
{
	int pix;

	pix = 17;
	t_params *p;

	p = (t_params *)pr;
	if (keycode == K_s)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, posx, posy++, 0150150150);
	if (keycode == K_z)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, posx, posy--, 0150150150);
	if (keycode == K_q)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, posx--, posy, 0150150150);
	if (keycode == K_d)
		while (pix-- > 0)
			mlx_pixel_put(p->mlx, p->win, posx++, posy, 0150150150);
	if (keycode == K_esc)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main()
{
	int			(*k)(int keycode, void *);
	int			(*m)(int button, int x, int y, void *);
	int 		map_file;
	t_params	p;
	
	k = &move;
	m = &mouse;
	ft_parse_map("map.cub", &p);
	p.mlx = mlx_init();
	if (p.mlx == NULL)
		puts("error");
	p.win = mlx_new_window(p.mlx, p.win_w, p.win_h, "My Window");
	mlx_mouse_hook(p.win, m, (void *)&p);
//	mlx_hook(p.win, 2, 1L<<0, k, (void *)&p);
	mlx_hook(p.win, 4, 1L<<2, m, (void *)&p);
	mlx_loop(p.mlx);
 	return (0);
}
