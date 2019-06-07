#include "Fdf.h"

void	key_rotate(t_fdf *data, int key)
{
	if (key == LEFT)
		data->y_rot -= 0.2;
	else if (key == RIGHT)
		data->y_rot += 0.2;
	else if (key == DOWN)
		data->x_rot -= 0.2;
	else if (key == UP)
		data->x_rot += 0.2;
	draw_map(data);
}

void	key_move(t_fdf *data, int key)
{
	if (key == A)
		data->x_move -= data->speed;
	else if (key == W)
		data->y_move -= data->speed;
	else if (key == D)
		data->x_move += data->speed;
	else if (key == S)
		data->y_move += data->speed;
	draw_map(data);
}

void	key_speed(t_fdf *data, int key)
{
	if (key == LESS)
		data->speed = (data->speed == 1) ? 1 : data->speed - 1;
	if (key == MORE)
		data->speed++;
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

int		key_event(int key, t_fdf *data)
{
	if (key == ESC)
		//exit (EXIT_SUCCESS);
		return (free_and_escape(data));
	if (key == LESS || key == MORE)
		key_speed(data, key);
	if (key == LEFT || key == DOWN || key == UP || key == RIGHT)
		key_rotate(data, key);
	if (key == W || key == A || key == S || key == D)
		key_move(data, key);
	if (key == R || key == F || key == I)
		key_height(data, key);
	if (key == DOT)
		key_filter(data, key);	
	if (key == C)
		key_color(data, key);
	if (key == P)
		key_projection(data, key);
	if (key >= KEY_1 && key <= KEY_6)
		key_color(data, key);
	return (0);
}