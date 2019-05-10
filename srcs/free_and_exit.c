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
			//x = 0;
			//wile (x < data->size_x)
			//{
				//printf("map[%d] free.\n", y);
				//ft_memdel((data)->map[y]);
			//	x++;
			//}
			y++;
		}
		//ft_memdel(data->map);
	}
	ft_memdel(&(data->mlx_ptr));
	ft_memdel(&data->win_ptr);
	ft_memdel(&data);
}

int		free_and_escape(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	all_free(data);
	exit(0);
	return (0);
}