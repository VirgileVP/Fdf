#include "Fdf.h"

void	all_free(t_fdf *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (data->map)
	{
		while (y < data->size_y)
		{
			x = 0;
			while (x < data->size_x)
			{
				printf("y = %d  |  x = %d\n", y, x);
				free(&data->map[y][x]);
				x++;
			}
			y++;
		}
		free(&data->map);
	}
	if (data->mlx_ptr)
		free(&data->mlx_ptr);
	//if (data->win_ptr)
	//	free(&data->win_ptr);
	/*if (data)
		free(&data);*/
}

int		free_and_escape(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	all_free(data);
	exit(1);
	return (0);
}