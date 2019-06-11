/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   3d_to_2d.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:53:00 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:53:02 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	invert_height(t_fdf *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			data->map[y][x].height = -data->map[y][x].height;
			x++;
		}
		y++;
	}
}

void	iso_projection(t_fdf *data, int y, int x)
{
	double old_x;
	double old_y;

	old_x = data->map[y][x].new_x;
	old_y = data->map[y][x].new_y;
	data->map[y][x].new_x = -(old_x - old_y) * -cos(M_PI / 6);
	data->map[y][x].new_y = -data->map[y][x].height + (old_x + old_y)
	* sin(M_PI / 6);
}

void	ortho_projection(t_fdf *data, int y, int x)
{
	data->map[y][x].new_x = (data->map[y][x].new_x * 25)
	/ (data->map[y][x].height + 30);
	data->map[y][x].new_y = (data->map[y][x].new_y * 25)
	/ (data->map[y][x].height + 30);
}

void	convertion(t_fdf *data, int y, int x, t_coord space)
{
	data->map[y][x].new_x = data->screen_max * 0.1 + space.x * x + x + 450;
	data->map[y][x].new_y = data->screen_max * 0.1 + space.y * y + y - 200;
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
}
