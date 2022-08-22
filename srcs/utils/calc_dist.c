#include "cub.h"

double	calc_dist(double x0, double x1, double y0, double y1)
{
	double	dist;

	dist = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	return (dist);
}
