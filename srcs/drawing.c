#include "Fdf.h"

void		draw_line(t_fdf *fdf, t_coord p1, t_coord p2)
{
	int	x;
	int	y;
	double coef;
	int ord;

	x = p1.x;
	y = 0;
	coef = (double)(p2.y - p1.y) / (p2.x - p1.x);
	ord = p1.y - coef * p1.x;
	while (x <= p2.x)
	{
		y = (int)(coef * x + ord);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFFFF00);
		x++;
	}
}