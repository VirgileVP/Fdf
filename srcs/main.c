/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:57:12 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:57:14 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_fdf *data)
{
	data->projection = 1;
	data->x_move = 0;
	data->y_move = 0;
	data->speed = 1;
	data->zoom = 0;
	data->height = 0;
	data->invert_height = 0;
	data->filter = 0;
	data->color = 4;
	data->r = 255;
	data->g = 255;
	data->b = 255;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIND_X, WIND_Y,
	"fdf  VVEYRAT-");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIND_X, WIND_Y);
	data->image = mlx_get_data_addr(data->img_ptr, &(data->bpp), &(data->s_l),
	&(data->endian));
}

void	fdf(t_fdf *data)
{
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 0, key_event, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_event, data);
	mlx_hook(data->win_ptr, 17, 0, free_and_escape, data);
	mlx_loop(data->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fdf	data;
	int		fd;

	if (ac != 2)
	{
		perror("Specify one map.\nUsage : ./fdf [map]\n");
		exit(1);
	}
	if (((fd = open(av[1], O_DIRECTORY)) != -1) ||
	((fd = open(av[1], O_RDONLY)) < 0))
	{
		perror("Impossible to open file.\n");
		exit(1);
	}
	if (read_map(&data, fd) == -1)
	{
		close(fd);
		perror("Reading failed.\n");
		exit(1);
	}
	init_struct(&data);
	fdf(&data);
	close(fd);
	return (0);
}
