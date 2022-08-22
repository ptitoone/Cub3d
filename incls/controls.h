#ifndef CONTROLS_H
# define CONTROLS_H

# include "cub.h"

int		key_w(t_params *p);
int		key_a(t_params *p);
int		key_s(t_params *p);
int		key_d(t_params *p);
int		key_a_l(t_params *p);
int		key_a_r(t_params *p);

int		key_press(int keycode, void *pr);
int		key_release(int keycode, void *pr);
int		destroy(void *pr);

#endif
