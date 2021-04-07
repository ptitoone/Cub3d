#ifndef CUB_H
#define CUB_H
# include "libft.h"
# include "errors.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# ifdef  __unix__

# define K_w	122
# define K_s	115
# define K_d	100
# define K_a	113
# define K_sp	32
# define K_a_u	65362
# define K_a_d	65364
# define K_a_r	65363
# define K_a_l	65361
# define K_esc	65307

# define M_l	1
# define M_m	2
# define M_r 	3
# define M_u 	4
# define M_d 	5

# elif defined __APPLE__

# define K_w	13
# define K_s	1
# define K_d	2
# define K_a	0
# define K_sp	49
# define K_a_u	126
# define K_a_d	125
# define K_a_r	124
# define K_a_l	123
# define K_esc	53

# define M_l	1
# define M_m	3
# define M_r 	2
# define M_u 	5
# define M_d 	4

# endif

# define PI		M_PI	
# define C_H	64	
# define TEX_S	128	

enum			e_dir
{NO, SO, WE, EA};

typedef struct	s_img
{

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}				t_img;

typedef struct	s_tex
{

	char	*dir[4];
	char	*sp;
	char	*f;
	char	*c;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;

}				t_tex;

typedef struct	s_play
{

	double	pos_x;
	double	pos_y;
	int		pos_block_x;
	int		pos_block_y;
	double	del_x;
	double	del_y;
	double	orient;
	double	strafe_orient;
	double	strafe_del_x;
	double	strafe_del_y;
	int		start_dir;

}				t_play;

typedef struct	s_map
{

	int		map_w;
	int		map_h;
	int		c_s;
	int		block_h;
	char	**map;
	int		*mapi;

}				t_map;

typedef struct	s_coords
{

	double	x;
	double	y;

}				t_coords;

typedef struct	s_keys
{

	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;

}				t_keys;

typedef struct	s_params
{

	void	*mlx;
	void	*win;
	void	*win2;
	int		win_w;
	int		win_h;
	double	ratio;
	t_tex	tex;
	t_play	player;
	t_map	map;
	t_img	img;
	t_img	imgv;
	t_keys	keys;

}				t_params;

typedef struct	s_draw_l
{

	int		wall_h;
	double	dist;
	double	ratio_y;
	int		tex_x;
	double	tex_y;
	double	ra;

}				t_draw_l;

int				init_params(t_params *p);
void			ft_init_keys(t_keys *k);
int				init_tex_img(t_params*p);
void			put_pixel(t_img *img, int x, int y, int color);
unsigned int 	get_pixel_color(t_img *img, int x, int y);
void			draw_player(int x, int y, t_params *p);
void			draw_player_ori(t_params *p);
int				ft_keys(int keycode, void *pr);
int				ft_keysr(int keycode, void *pr);
int				mouse(int x, int y, void *pr);
void    		plot_line(int x0, int y0, int x1, int y1, int color, t_params *p);
int				find_wall(t_params *p);
void			upscale_img(int w, int h, int scale, char *img, char *img2);
void			draw_tex_col(t_img *tex, int tex_x, int tex_y, int rc, int j, t_img *img);
void			draw_line_h(int rc, double ra, double x, double y, t_params *p, int color);
void			draw_line_v(int rc, double ra, double x, double y, t_params *p, int color);
#endif
