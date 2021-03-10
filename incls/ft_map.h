#ifndef FT_MAP
#define	FT_MAP

#include "cub.h"

int		ft_parse_map(char *map_file, t_params *p);
int		ft_parse_res(char *line, t_params *p);
int		ft_parse_tex(char *line, t_tex *t);
int		ft_parse_size(char *line, t_params *p);
int		ft_build_map(char *line, t_params *p);

#endif
