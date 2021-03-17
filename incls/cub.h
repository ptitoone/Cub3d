#ifndef CUB_H
#define CUB_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifdef  __unix__

# define K_z	122
# define K_s	115
# define K_d	100
# define K_q	113
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

# define K_z	13
# define K_s	1
# define K_d	2
# define K_q	0
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

# define PI		3.14159	
# define C_H	64

enum			e_dir
{NO, SO, WE, EA};

typedef struct	s_tex
{

	char	*dir[4];
	char	*sp;
	char	*f;
	char	*c;

}				t_tex;

typedef struct	s_play
{

	int		pos_x;
	int		pos_y;
	float	orient;

}				t_play;

typedef struct	s_map
{

	int		map_w;
	int		map_h;
	int		block_h;
	int		block_w;
	char	**map;

}				t_map;

typedef struct	s_img
{

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}				t_img;

typedef struct	s_params
{

	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	t_tex	tex;
	t_play	player;
	t_map	map;
	t_img	img;

}				t_params;

void			ft_init_params(t_params *p);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int 	ft_get_pixel_color(t_img *img, int x, int y);
void			ft_draw_player(int x, int y, t_params *p);
void			ft_draw_player_ori(t_params *p);
int				ft_keys(int keycode, void *pr);
int				ft_mouse(int keycode, int x, int y, void *pr);
void    		ft_plot_line(int x0, int y0, int x1, int y1, int color, t_params *p);
int				 ft_find_wall(t_params *p);
#endif
