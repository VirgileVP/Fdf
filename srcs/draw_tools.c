#include "Fdf.h"

void		put_pixel(t_fdf *data, int x, int y , int height)
{
	int		index;

	if (x >= 0 && x <= WIND_X && y >= 0 && y <= WIND_Y)
	{
		index = y * WIND_X + x;
		data->image[index] = height;
	}
}

void		pixel_color(t_fdf *data, int x, int y , unsigned long height)
{
	if (height != 0)
		put_pixel(data, x, y, height);
    else if (data->color == 0)
		put_pixel(data, x, y, 0xFFFFFF);
	else if (data->color == 1)
		put_pixel(data, x, y, 0xFF0000);
	else if (data->color == 2)
		put_pixel(data, x, y, 0x00FF00);
	else if (data->color == 3)
		put_pixel(data, x, y, 0x0000FF);
	else if (data->color == 4)
		put_pixel(data, x, y, 0xFFaa00);
	else if (data->color == 5)
		put_pixel(data, x, y, 0x00aaFF);
	else if (data->color == 6)
		put_pixel(data, x, y, 0xaa00FF);
	else if (data->color == 7)
		put_pixel(data, x, y, 0xEEDDFF);
	else if (data->color == 8)
		put_pixel(data, x, y, 0xCCCCFF);
	else if (data->color == 9)
		put_pixel(data, x, y, 0xFFEECC);
}

void		draw_line(t_fdf *data, t_coord a, t_coord b, unsigned long height)
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
			pixel_color(data, a.x, a.y, height);
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


