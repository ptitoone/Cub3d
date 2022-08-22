#ifndef DRAW_H
# define DRAW_H

void			put_pixel(t_img *img, int x, int y, int color);
unsigned int	get_pixel_color(t_img *img, int x, int y);

void			draw_line_h(int rc, double ra, t_coords *c, t_params *p);
void			draw_line_v(int rc, double ra, t_coords *c, t_params *p);
void			draw_sprites(t_params *p);

#endif
