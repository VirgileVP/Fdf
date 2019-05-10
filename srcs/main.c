#include "Fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*data;
	int		fd;

	fd = 0;
	if (ac != 2)
		perror("Specify a map.");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		perror("Impossible to open file.");
	if (!(data = malloc(sizeof(t_fdf) + 1)))
		return (0);
	if (read_map(data, fd) == -1)
	{
		free(data->map);
		free(data);
		perror("Reading failed.");
		exit(1);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIND_X, WIND_Y, "fdf 42");
	menu(data);
	map_3d_to_2d(data);
	draw_map(data, data->map);
	mlx_key_hook(data->win_ptr, key_event, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}