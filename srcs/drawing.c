#include "Fdf.h"

void		next_draw_x(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (x + 2 <= data->size_x)
	{
		point.x = data->screen_max * 20 / 100 + space.x * data->map[y][x].new_x;
		point.y = data->screen_max * 20 / 100 + space.y * data->map[y][x].new_y;
		point2.x = data->screen_max * 20 / 100 + space.x * (data->map[y][x].new_x);
		point2.y = point.y;
		draw_line(data, point, point2, 0/*data->map[y][x].height*/);
	}
}

void		next_draw_y(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (y + 2 <= data->size_y)
	{
		point.x = data->screen_max * 20 / 100 + space.x * data->map[y][x].new_x;
		point.y = data->screen_max * 20 / 100 + space.y * data->map[y][x].new_y;
		point2.x = point.x;
		point2.y = data->screen_max * 20 / 100 + space.y * (data->map[y][x].new_y);
		draw_line(data, point, point2, 0/*data->map[y][x].height*/);
	}
}

void		draw_map(t_fdf *data, t_pixel **map)
{
	int		x;
	int		y;
	t_coord	space;

	x = 0;
	y = 0;
	data->screen_max = (WIND_X >= WIND_Y) ? WIND_Y : WIND_X ;
	space.x = (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
	space.y = (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
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

void		map_3d_to_2d(t_fdf *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			//printf("x = %d   new_x = %d\ny = %d   new_y = %d\n\n", x, x - data->map[y][x].height * x / data->map[y][x].height, y, y - data->map[y][x].height * y / data->map[y][x].height);
			//printf("height = %d | x = %d | new = %d\n", data->map[y][x].height, x, x + 0.71 * data->map[y][x].height);
			data->map[y][x].new_x = x;// + 0.81 * data->map[y][x].height;
			data->map[y][x].new_y = y;// + 0.81 * data->map[y][x].height;
			x++;
		}
		y++;
	}
}