#include "Fdf.h"

void		draw_x(t_fdf *data, int x, int y)
{
	//printf("   x = %2d | x + 1 = %2d", x , x + 1);
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x;
	point.y = data->map[y][x].new_y;
	point2.x = data->map[y][x + 1].new_x;
	point2.y = point.y;
	//printf("   [x = %2d | x2 = %2d]", point.x , point2.x);
	draw_line(data, point, point2, 0xffaa00);
}

void		draw_y(t_fdf *data, int x, int y)
{
	//printf("   y = %2d | y + 1 = %2d", y , y + 1);
	//printf("  map[%2d][%2d] : new_y = %4d  ", x, y, data->map[y + 1][x].new_y);
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x;
	point.y = data->map[y][x].new_y;
	point2.x = point.x;
	point2.y = data->map[y + 1][x].new_y;
	//printf("  #map[%d][%d2]=%4d#  ", y+1, x, data->map[y + 1][x].new_x);
	printf("[y:%2d x:%2d| y2:%4d x2:%2d]\n", point.y, point.x , point2.y, point2.x);
	draw_line(data, point, point2, 0xffaa00);
}

void		convert_point(t_fdf *data)
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
			data->map[y][x].new_x = data->screen_max * 20 / 100 + x + space.x * x;
			data->map[y][x].new_y = data->screen_max * 20 / 100 + y + space.y * y;
			//data->map[y][x].new_x = (data->map[y][x].new_x * 1) / (data->map[y][x].height + 2.5);
			//data->map[y][x].new_y = (data->map[y][x].new_y * 1) / (data->map[y][x].height + 2.5);
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
			//printf("\ny = %2d,  x = %2d",y, x);
			//printf("\nsize_y = %2d, size_x = %2d, map[%2d][%2d] : new_x = %4d | new_y = %3d", data->size_y, data->size_x , y, x, data->map[y][x].new_x, data->map[y][x].new_y);
			//printf("  map[%2d][%2d] : new_y = %4d  ", x, y, data->map[y+1][x].new_y);
			if (y + 2 <= data->size_y)
				draw_y(data, x, y);
			if (x + 1 < data->size_x)
				draw_x(data, x, y);
			x++;
		}
		y++;
	}
	printf("\nfinish\n");
}