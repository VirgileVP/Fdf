#include "Fdf.h"

void		pixel_color(t_fdf *data, int x, int y , unsigned long high)
{
	if (high != 0)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, high);
    else if (data->color == 0)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
	else if (data->color == 1)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
	else if (data->color == 2)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FF00);
	else if (data->color == 3)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x0000FF);
	else if (data->color == 4)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFaa00);
	else if (data->color == 5)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00aaFF);
	else if (data->color == 6)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xaa00FF);
	else if (data->color == 7)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xEEDDFF);
	else if (data->color == 8)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xCCCCFF);
	else if (data->color == 9)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFEECC);
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


