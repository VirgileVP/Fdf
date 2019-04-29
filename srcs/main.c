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
	read_map(data, fd);
	/*data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf 42");
	mlx_loop(data->mlx_ptr);
	*/return 0;
}