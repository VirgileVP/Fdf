#include "Fdf.h"

void		draw_x(t_fdf *data, int x, int y)
{
	//printf("   x = %2d | x + 1 = %2d", x , x + 1);
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x + data->x_move;
	point.y = data->map[y][x].new_y + data->y_move;
	point2.x = data->map[y][x + 1].new_x + data->x_move;
	point2.y = data->map[y][x + 1].new_y + data->y_move;
	//printf("   [x = %2d | x2 = %2d]", point.x , point2.x);
	//printf(" [y:%3d x:%4d| y2:%3d x2:%4d]", point.y, point.x , point2.y, point2.x);
	draw_line(data, point, point2, 0xffaa00);
}

void		draw_y(t_fdf *data, int x, int y)
{
	//printf("   y = %2d | y + 1 = %2d", y , y + 1);
	//printf("  map[%2d][%2d] : new_y = %4d  ", x, y, data->map[y + 1][x].new_y);
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x + data->x_move;
	point.y = data->map[y][x].new_y + data->y_move;
	point2.x = data->map[y + 1][x].new_x + data->x_move;
	point2.y = data->map[y + 1][x].new_y + data->y_move;
	//printf("  #map[%d][%d2]=%4d#  ", y+1, x, data->map[y + 1][x].new_x);
	//printf("[y:%3d x:%4d| y2:%3d x2:%4d]\n", point.y, point.x , point2.y, point2.x);
	draw_line(data, point, point2, 0xffaa00);
}

void		convert_draw_map(t_fdf *data)
{
	int		x;
	int		y;
	t_coord	space;

	x = 0;
	y = 0;
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
				if (data->high == 1 && data->map[y][x].height + 1 == -30)
					data->map[y][x].height += 2;
				else if (data->high == 1)
					data->map[y][x].height++;
				if (data->high == -1 && data->map[y][x].height - 1 == -30)
					data->map[y][x].height -= 2;
				else if (data->high == -1)
					data->map[y][x].height--;
			}
			data->map[y][x].new_x = data->screen_max * 20 / 100 + x + space.x * x;
			data->map[y][x].new_y = data->screen_max * 20 / 100 + y + space.y * y;
			data->map[y][x].new_x = (data->map[y][x].new_x * 25) / (data->map[y][x].height + 30);
			data->map[y][x].new_y = (data->map[y][x].new_y * 25) / (data->map[y][x].height + 30);
			data->map[y][x].new_x = (cos(data->x_rot) * data->map[y][x].new_x) - (sin(data->x_rot) * data->map[y][x].new_y);
			data->map[y][x].new_y = (sin(data->x_rot) * data->map[y][x].new_x) - (cos(data->x_rot) * data->map[y][x].new_y);
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
	//printf("\nfinish\n");
}