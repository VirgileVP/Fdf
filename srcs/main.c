#include "Fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	fd = 0;
	if (ac != 2)
		perror("Specify a map.");
	if ((fd = open(ac[1], O_RDONLY)) == -1)
		perror("Impossible to open file.");
	if (!(fdf = malloc(sizeof(t_fdf) + 1)))
		return (0);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf 42");

	parsing(fdf, );
	mlx_loop(fdf->mlx_ptr);
	return 0;
}