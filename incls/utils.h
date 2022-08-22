#ifndef UTILS_H
# define UTILS_H

# include "cub.h"

int		free_line(char **line);
int		free_params(t_params *p);
double	calc_dist(double x0, double x1, double y0, double y1);
void	save_view(t_params *p);

#endif