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
	data->wind_x = 500;
	data->wind_y = 500;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->wind_x, data->wind_y, "fdf 42");
	draw_map(data, data->map);
	mlx_loop(data->mlx_ptr);
	return 0;
}