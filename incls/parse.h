#ifndef PARSE_H
# define	PARSE_H

# include "cub.h"

int		parse_file(char *map_file, t_params *p);
int		parse_res(char *line, t_params *p);
int		parse_tex(char *line, t_params *p);
int		parse_map_size(int map_fd, t_params *p);
int		is_map_vert_end_line(char const *l);
int		is_valid_map_line(char const *l);
int		is_pos(char c);
int		is_tex_spec(char c);
int		is_sprite_spec(char c);
int		init_map(char *map_file, t_params *p);
int		extract_rgb_value(char *str);

#endif
