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

int		free_and_escape(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}
