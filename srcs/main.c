#include "Fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*data;
	int		fd;

	fd = 0;
	if (ac != 2)
		perror("Specify a map.");
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		perror("Impossible to open file.");
		exit(0);
	}
	if (!(data = malloc(sizeof(t_fdf) + 1)))
		return (0);
	if (read_map(data, fd) == -1)
	{
		free(data->map);
		free(data);
		perror("Reading failed.");
		exit(1);
	}
	data->projection = 1;
	data->x_rot = 0;
	data->y_rot = 0;
	data->x_move = 0;
	data->y_move = 0;
	data->speed = 1;
	data->zoom = 0;
	data->high = 0;
	data->filter = 0;
	data->color = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIND_X, WIND_Y, "fdf 42");
	//if ()
	//data->map[y][x].height = data->map[y][x].height * -1;
	HUD(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 0, key_event, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_event, data);
	//mlx_hook(data->win_ptr, 5, 0, key_event, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}