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

void		draw_map(t_fdf *data)
{
	int		x;
	int		y;
	t_coord	space;

	x = 0;
	y = 0;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIND_X, WIND_Y);
	data->image = mlx_get_data_addr(data->img_ptr, &(data->bpp), &(data->s_l), &(data->endian));
	if (data->invert_height == 1)
		invert_height(data);
	HUD(data);
	data->screen_max = (WIND_X >= WIND_Y) ? WIND_Y : WIND_X ;
	space.x = data->zoom + (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
	space.y = data->zoom + (data->screen_max - data->screen_max * (40 / 100)) / data->size_x;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			data->map[y][x].new_x = data->screen_max * 20 / 100 + x + space.x * x;
			data->map[y][x].new_y = data->screen_max * 20 / 100 + y + space.y * y;
			//do_rotate(data, y, x);
			if (data->map[y][x].no_height != 1)
			{
				if (data->height == 1 && data->map[y][x].height * 1.1 == 0)
					data->map[y][x].height *= 1.2;
				else if (data->height == 1)
					data->map[y][x].height *= 1.1;
				else if (data->height == -1 && data->map[y][x].height * 0.9 == 0)
					data->map[y][x].height *= 0.8;
				else if (data->height == -1)
					data->map[y][x].height *= 0.9;
			}
			if (data->projection == 1)
				iso_projection(data, y, x);
			else if (data->projection == 2)
				ortho_projection(data, y, x);
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (y + 2 <= data->size_y)
				draw_y(data, x, y);
			if (x + 2 <= data->size_x)
				draw_x(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->image, data->win_ptr, data->img_ptr, 0, 0);
	HUD_text(data);
	data->height = 0;
	data->invert_height = 0;
}