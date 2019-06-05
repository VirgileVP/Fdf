#include "Fdf.h"

void	invert_height(t_fdf *data)
{
	
}

void	iso_projection(t_fdf *data, int y, int x)
{
	double old_x;
	double old_y;

	old_x = data->map[y][x].new_x;
	old_y = data->map[y][x].new_y;
	data->map[y][x].new_x = (old_x - old_y) * cos(0.523599);
	data->map[y][x].new_y = -data->map[y][x].height + (old_x + old_y) * sin(0.523599);
}

void	ortho_projection(t_fdf *data, int y, int x)
{		
	data->map[y][x].new_x = (data->map[y][x].new_x * 25) / (data->map[y][x].height + 30);
	data->map[y][x].new_y = (data->map[y][x].new_y * 25) / (data->map[y][x].height + 30);
}