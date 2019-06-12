/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_events.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:56:46 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:57:06 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	key_move(t_fdf *data, int key)
{
	if (key == LESS)
		data->speed = (data->speed == 1) ? 1 : data->speed - 1;
	if (key == MORE)
		data->speed++;
	if (key == A || key == Q || key == Z)
		data->x_move += data->speed;
	if (key == W || key == Q || key == E)
		data->y_move += data->speed;
	if (key == D || key == C || key == E)
		data->x_move -= data->speed;
	if (key == S || key == Z || key == C)
		data->y_move -= data->speed;
	draw_map(data);
}

void	key_height(t_fdf *data, int key)
{
	if (key == R)
		data->height = 1;
	else if (key == F)
		data->height = -1;
	else if (key == I && data->invert_height == 0)
		data->invert_height = 1;
	else if (key == I && data->invert_height == 1)
		data->invert_height = 0;
	draw_map(data);
}

void	key_filter(t_fdf *data, int key)
{
	if (data->filter == 3)
		data->filter = 0;
	else
		data->filter++;
	draw_map(data);
}

void	key_color(t_fdf *data, int key)
{
	if (key == KEY_1 && data->r >= 4)
		data->r -= 5;
	else if (key == KEY_4 && data->r <= 251)
		data->r += 5;
	else if (key == KEY_2 && data->g >= 4)
		data->g -= 5;
	else if (key == KEY_5 && data->g <= 251)
		data->g += 5;
	else if (key == KEY_3 && data->b >= 4)
		data->b -= 5;
	else if (key == KEY_6 && data->b <= 251)
		data->b += 5;
	draw_map(data);
}

void	key_projection(t_fdf *data, int key)
{
	if (data->projection == 2)
		data->projection = 1;
	else
		data->projection++;
	data->height = 0;
	draw_map(data);
}
