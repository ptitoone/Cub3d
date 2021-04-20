#ifndef PARSE_H
#define	PARSE_H

#include "cub.h"

int		parse_file(char *map_file, t_params *p);
int		parse_res(char *line, t_params *p);
int		parse_tex(char *line, t_tex *t);
int		parse_map_size(int map_fd, t_params *p);
int		is_pos(char c);
int		is_tex_specifier(char c);
int		lay_map(char *map_file, t_params *p);
int		extract_rgb_value(char *str);
int		draw_map(t_params *p);

#endif
