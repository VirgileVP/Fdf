/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_and_exit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:53:38 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:53:40 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

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
			//ft_memdel((void*)data->map[y]);
			y++;
		}
		ft_memdel((void**)data->map);
	}
	ft_memdel((void*)data);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}

int		free_and_escape(t_fdf *data)
{
	all_free(data);
	exit(0);
	return (0);
}
