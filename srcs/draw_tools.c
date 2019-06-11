/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:53:27 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:53:29 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_fdf *data, int x, int y)
{
	int		index;

	if (x > 0 && x < (WIND_X) && y > 150 && y < (WIND_Y))
	{
		index = y * WIND_X + x;
		index = index * 4;
		data->image[index] = data->b;
		data->image[index + 1] = data->g;
		data->image[index + 2] = data->r;
		data->image[index + 3] = 0;
	}
}

void		draw_line(t_fdf *data, t_coord a, t_coord b)
{
	t_line_draw	line;

	line.diff_x = abs(b.x - a.x);
	line.orient_x = a.x < b.x ? 1 : -1;
	line.diff_y = abs(b.y - a.y);
	line.orient_y = a.y < b.y ? 1 : -1;
	line.e = (line.diff_x > line.diff_y ? line.diff_x : -line.diff_y) / 2;
	while (1)
	{
		if (a.x >= 0 && a.x <= WIND_X && a.y >= 0 && a.y <= WIND_Y)
			put_pixel(data, a.x, a.y);
		if (a.x == b.x && a.y == b.y)
			break ;
		line.e2 = line.e;
		if (line.e2 > -line.diff_x)
		{
			line.e -= line.diff_y;
			a.x += line.orient_x;
		}
		if (line.e2 < line.diff_y)
		{
			line.e += line.diff_x;
			a.y += line.orient_y;
		}
	}
}
