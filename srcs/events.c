#include "Fdf.h"

void	key_rotate(t_fdf *data, int key)
{
	if (key == LEFT)
		data->y_rot -= 1;
	else if (key == RIGHT)
		data->y_rot += 1;
	else if (key == DOWN)
		data->x_rot -= 1;
	else if (key == UP)
		data->x_rot += 1;
	printf("x_rot = %d | y_rot = %d\n", data->x_rot, data->y_rot);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	HUD(data);
	convert_draw_map(data);
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	HUD(data);
	convert_draw_map(data);
}

void	key_speed(t_fdf *data, int key)
{
	if (key == LESS)
		data->speed = (data->speed == 1) ? 1 : data->speed - 1;
	if (key == MORE)
		data->speed++;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	HUD(data);
	convert_draw_map(data);
}

void	key_high(t_fdf *data, int key)
{
	if (key == R)
		data->high = 1;
	if (key == F)
		data->high = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	HUD(data);
	convert_draw_map(data);
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
	if (key == R || key == F)
		key_high(data, key);
	return (0);
}