#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <time.h>

# ifdef	__unix__

# define K_W	122
# define K_S	115
# define K_D	100
# define K_A	113
# define K_SP	32
# define K_A_U	65362
# define K_A_D	65364
# define K_A_R	65363
# define K_A_L	65361
# define K_ESC	65307

# elif defined __APPLE__

# define K_W	13
# define K_S	1
# define K_D	2
# define K_A	0
# define K_SP	49
# define K_A_U	126
# define K_A_D	125
# define K_A_R	124
# define K_A_L	123
# define K_ESC	53

#endif

# define PI		M_PI	
# define C_S	64
# define TEX_S	64

enum			e_dir
{
	NO,
	SO,
	WE,
	EA,
	S1
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_tex_type
{
	char			*path;
	t_img			img;
	unsigned int	clr[TEX_S][TEX_S];
}				t_tex_type;

typedef struct s_tex
{
	t_tex_type		type[5];
	char			*f;
	unsigned int	f_color;
	char			*c;
	unsigned int	c_color;
}				t_tex;

typedef struct s_play
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

typedef struct s_map
{
	int		map_w;
	int		map_h;
	char	**map;
}				t_map;

typedef struct s_coords
{
	double	x;
	double	y;
}				t_coords;

typedef struct s_counter
{
	int	i;
	int	j;
	int	count;
}				t_counter;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
}				t_keys;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		scrn_x;
	double	dist;
	int		visible;
	int		tex;
}				t_sprite;

typedef struct s_sprite_data
{
	double		*col_dist;
	t_sprite	*sprites;
	int			count;
}				t_sprite_data;

typedef struct s_param_count
{
	int resolution;
	int north_tex;
	int south_tex;
	int west_tex;
	int east_tex;
	int sprite_tex;
	int floor_rgb;
	int ceiling_rgb;

}				t_param_count;

typedef struct s_params
{
	void			*mlx;
	void			*win;
	int				win_w;
	int				win_h;
	int 			save_bmp;
	t_tex			tex;
	t_play			player;
	t_map			map;
	t_img			img;
	t_img			frame;
	t_keys			keys;
	t_sprite_data	s_data;
}				t_params;

typedef struct s_draw_l
{
	int		wall_h;
	double	dist;
	double	step_y;
	int		tex_x;
	double	tex_y;
	double	ra;
}				t_draw_l;

typedef struct s_draw_s
{
	int		sprite_h;
	int		x;
	int		y;
	double	step;
	double	tex_x;
	double	tex_y;
	int		i;
	int		j;
	int		texno;
}				t_draw_s;

#endif
