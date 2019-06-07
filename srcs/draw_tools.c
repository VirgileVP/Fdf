#include "Fdf.h"

void		put_pixel(t_fdf *data, int x, int y)
{
	int		index;

	if (x >= 0 && x <= WIND_X * 4 && y >= 150 && y < WIND_Y * 4)
	{
		index = y * WIND_X + x;
		index = index * 4;
		data->image[index] = data->b;
		data->image[index + 1] = data->g;
		data->image[index + 2] = data->r;
		data->image[index + 3] = 0;
	}
}

void		draw_line(t_fdf *data, t_coord a, t_coord b)
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
			put_pixel(data, a.x, a.y);
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


