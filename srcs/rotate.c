#include "Fdf.h"

static void	rotate_x(t_fdf *data, int y, int x)
{
	int old_y;

	old_y = data->map[y][x].new_y;
	data->map[y][x].new_y = old_y * cos(data->x_rot) + data->map[y][x].height * sin(data->x_rot);
	data->map[y][x].height = -old_y * sin(data->x_rot) + data->map[y][x].height * cos(data->x_rot);
}

static void	rotate_y(t_fdf *data, int y, int x)
{
	int old_x;

	old_x = data->map[y][x].new_x;
	data->map[y][x].new_x = old_x * cos(data->y_rot) + data->map[y][x].height * sin(data->y_rot);
	data->map[y][x].height = -old_x * sin(data->y_rot) + data->map[y][x].height * cos(data->y_rot);
}

void		do_rotate(t_fdf *data, int y, int x)
{
    rotate_x(data, y, x);
    rotate_y(data, y, x);
}
