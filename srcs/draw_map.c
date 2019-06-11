/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:53:18 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:53:20 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		draw_x(t_fdf *data, int x, int y)
{
	t_coord	point;
	t_coord	point2;

	point.x = data->map[y][x].new_x + data->x_move;
	point.y = data->map[y][x].new_y + data->y_move;
	point2.x = data->map[y][x + 1].new_x + data->x_move;
	point2.y = data->map[y][x + 1].new_y + data->y_move;
	if (data->filter == 1)
		put_pixel(data, point.x, point.y);
	if (data->filter == 0 || data->filter == 2)
		draw_line(data, point, point2);
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
		put_pixel(data, point.x, point.y);
	if (data->filter == 0 || data->filter == 3)
		draw_line(data, point, point2);
}

void		printing(t_fdf *data)
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
			if (y + 2 <= data->size_y)
				draw_y(data, x, y);
			if (x + 2 <= data->size_x)
				draw_x(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->image, data->win_ptr, data->img_ptr, 0, 0);
	hud_text(data);
	data->height = 0;
	data->invert_height = 0;
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
	hud(data);
	data->screen_max = (WIND_X <= WIND_Y - 150) ? WIND_Y - 150 : WIND_X ;
	space.x = data->zoom + (data->screen_max - (data->screen_max * 0.5)) / data->size_x;
	space.y = data->zoom + (data->screen_max - (data->screen_max * 0.5)) / data->size_x;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			convertion(data, y, x, space);
			x++;
		}
		y++;
	}
	printing(data);
}
