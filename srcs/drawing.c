#include "Fdf.h"

void		draw_line(t_fdf *fdf, t_coord p0, t_coord p1)
{
	t_coord	temp;
	int		coef;
	int		delta_x;
	int		delta_y;

	delta_x = p1.x - p0.x;
	delta_y = p1.y - p0.y;

	temp.x = p0.x;
	temp.y = p0.y;

	coef = 2 * delta_x - delta_y;
	while (temp.x <= p1.x)
	{
		if (coef >= 0)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, temp.x, temp.y, 0xFFAA55);
			temp.y++;
			coef = coef + 2 * delta_y - 2 * delta_x;
		}
		else
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, temp.x, temp.y, 0xFFAA55);
			coef = coef + 2 * delta_y;
		}
		temp.x++;
	}
}

void		next_draw_x(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (x + 1 <= data->size_x)
	{
		point.x = data->wind_x * 20 / 100 + space.x * x;
		point.y = data->wind_y * 20 / 100 + space.y * y;
		point2.x = data->wind_x * 20 / 100 + space.x * (x + 1);
		point2.y = point.y;
		draw_line(data, point, point2);
	}
}

void		next_draw_y(t_fdf *data, int x, int y, t_coord space)
{
	t_coord	point;
	t_coord	point2;

	if (y + 1 <= data->size_y)
	{
		point.x = data->wind_x * 20 / 100 + space.x * x;
		point.y = data->wind_y * 20 / 100 + space.y * y;
		point2.x = point.x;
		point2.y = data->wind_y * 20 / 100 + space.y * (y + 1);
		draw_line(data, point, point2);
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
