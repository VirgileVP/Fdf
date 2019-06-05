#include "Fdf.h"

void		draw_x(t_fdf *data, int x, int y)
{
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x + data->x_move;
	point.y = data->map[y][x].new_y + data->y_move;
	point2.x = data->map[y][x + 1].new_x + data->x_move;
	point2.y = data->map[y][x + 1].new_y + data->y_move;
	if (data->filter == 1)
		pixel_color(data, point.x, point.y, 0);
	if (data->filter == 0 || data->filter == 2)
	{
		draw_line(data, point, point2, 0);
	}
}

void		draw_y(t_fdf *data, int x, int y)
{
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x + data->x_move;
	point.y = data->map[y][x].new_y + data->y_move;
	point2.x = data->map[y + 1][x].new_x + data->x_move;
	point2.y = data->map[y + 1][x].new_y + data->y_move;
	if (data->filter == 1)
		pixel_color(data, point.x, point.y, 0);
	if (data->filter == 0 || data->filter == 3)
	{
		draw_line(data, point, point2, 0);
	}
}

void		do_rotate(t_fdf *data, int y, int x)
{
	data->map[y][x].new_x = x;
	data->map[y][x].new_y = data->map[y][x].new_y * cos(data->x_rot) + data->map[y][x].height * sin(data->x_rot);
	data->map[y][x].height = -data->map[y][x].new_y * sin(data->x_rot) + data->map[y][x].height * cos(data->x_rot);
	data->map[y][x].new_x = data->map[y][x].new_x * cos(data->y_rot) + data->map[y][x].height * sin(data->y_rot);
	data->map[y][x].new_y = -data->map[y][x].new_y * sin(data->y_rot) + data->map[y][x].height * cos(data->y_rot);

}

void		draw_map(t_fdf *data)
{
	int		x;
	int		y;
	t_coord	space;

	x = 0;
	y = 0;
	ft_putnbr(data->size_y);
	ft_putchar('\n');
	if (data->invert_high == 1)
		invert_height(data);
	ft_putnbr(data->size_y);
	ft_putchar('\n');
	data->screen_max = (WIND_X >= WIND_Y) ? WIND_Y : WIND_X ;
	space.x = data->zoom + (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
	space.y = data->zoom + (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (data->map[y][x].no_high != 1)
			{
				if (data->high == 1 && data->map[y][x].height * 1.1 == 0)
					data->map[y][x].height *= 1.2;
				else if (data->high == 1)
					data->map[y][x].height *= 1.1;
				else if (data->high == -1 && data->map[y][x].height * 0.9 == 0)
					data->map[y][x].height *= 0.8;
				else if (data->high == -1)
					data->map[y][x].height *= 0.9;
			}
			data->map[y][x].new_x = data->screen_max * 20 / 100 + x + space.x * x;
			data->map[y][x].new_y = data->screen_max * 20 / 100 + y + space.y * y;
			if (data->projection == 1)
				iso_projection(data, y, x);
			else if (data->projection == 2)
				ortho_projection(data, y, x);
			//do_rotate(data, y, x);
			//printf("[%2d:%2d] %4d %4d | ", y, x, data->map[y][x].new_y, data->map[y][x].new_x);
			x++;
		}
		//printf("\n");
		y++;
	}
	x = 0;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			//printf("y = %2d,  x = %2d",y, x);
			//printf("\nsize_y = %2d, size_x = %2d, map[%2d][%2d] : new_x = %4d | new_y = %3d", data->size_y, data->size_x , y, x, data->map[y][x].new_x, data->map[y][x].new_y);
			//printf("\nmap[%2d][%2d] = %4d %4d ", y, x, data->map[y][x].new_y, data->map[y][x].new_x);
			if (y + 2 <= data->size_y)
				draw_y(data, x, y);
			if (x + 2 <= data->size_x)
				draw_x(data, x, y);
			x++;
		}
		y++;
	}
	data->high = 0;
	data->x_rot = 0;
	data->y_rot = 0;
	//printf("\nfinish\n");
}