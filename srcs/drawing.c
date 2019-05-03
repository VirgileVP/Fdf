#include "Fdf.h"

void		next_draw_x(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (x + 2 <= data->size_x)
	{
		point.x = data->wind_x * 20 / 100 + space.x * x;
		point.y = data->wind_y * 20 / 100 + space.y * y;
		point2.x = data->wind_x * 20 / 100 + space.x * (x + 1);
		point2.y = point.y;
		draw_line(data, point, point2, data->map[y][x]);
	}
}

void		next_draw_y(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (y + 2 <= data->size_y)
	{
		point.x = data->wind_x * 20 / 100 + space.x * x;
		point.y = data->wind_y * 20 / 100 + space.y * y;
		point2.x = point.x;
		point2.y = data->wind_y * 20 / 100 + space.y * (y + 1);
		draw_line(data, point, point2, data->map[y][x]);
	}
}

void		draw_map(t_fdf *data, int **map)
{
	int		x;
	int		y;
	t_coord	space;

	x = 0;
	y = 0;
	space.x = (data->wind_x - data->wind_x * 40 / 100) / data->size_x;
	space.y = (data->wind_x - data->wind_x * 40 / 100) / data->size_x;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			next_draw_x(data, x, y, space);
			next_draw_y(data, x, y, space);
			x++;
		}
		y++;
	}
}
