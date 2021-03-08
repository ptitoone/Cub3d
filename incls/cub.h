#ifndef CUB_H
#define CUB_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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

# define BLK_H	5	
# define BLK_W	5

typedef struct	s_tex
{

	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sp;
	int		cl;
	int		fl;

}				t_tex;

typedef struct	s_play
{

	float	pos_x;
	float	pos_y;
	float	orient;

}				t_play;

typedef struct	s_map
{

	int		map_w;
	int		map_h;
	void	*map;

}				t_map;

typedef struct	s_params
{

	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	t_tex	tex;
	t_play	player;
	t_map	map;

}				t_params;

#endif
