#ifndef INIT_H
# define INIT_H

# include "cub.h"

int	init_params(t_params *p);
int	check_player_pos(t_params *p);
int	init_sprites(t_params *p);
int	init_tex_img(t_params *p, int i);
int	init_map(char *map_file, t_params *p);

#endif