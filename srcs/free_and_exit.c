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
			//ft_memdel((void**)data->map[y]);
			y++;
		}
		ft_memdel((void**)data->map);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//ft_memdel((void**)data);
	printf("data free\n");
}

int		free_and_escape(t_fdf *data)
{
	//all_free(data);
	exit(0);
	return (0);
}