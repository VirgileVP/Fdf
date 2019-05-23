#include "Fdf.h"

void		pixel_color(t_fdf *data, int x, int y , unsigned long high)
{
    if (high == 0)
	{
		printf("high = 0.\n");
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
	}
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, high);
}

void		draw_line(t_fdf *data, t_coord a, t_coord b, unsigned long high)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;
	int e2;

	dx = abs(b.x - a.x);
	sx = a.x < b.x ? 1 : -1;
	dy = abs(b.y - a.y);
	sy = a.y < b.y ? 1 : -1;
	e = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		if(a.x >= 0 && a.x <= WIND_X && a.y >= 0 && a.y <= WIND_Y)
			pixel_color(data, a.x, a.y, high);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = e;
		if (e2 > -dx)
		{
			e -= dy;
			a.x += sx;
		}
		if (e2 < dy)
		{
			e += dx;
			a.y += sy;
		}
	}
}


