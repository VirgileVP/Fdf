/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_tools.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 14:28:44 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 14:28:45 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			size_y(char *read)
{
	int		index;
	int		ret;

	index = 0;
	ret = 0;
	while (read[index])
	{
		if (read[index] == '\n')
			ret++;
		index++;
	}
	return (ret);
}

int			init_tab(t_fdf *data, char *read)
{
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	data->size_y = size_y(read);
	data->map = NULL;
	if (!(data->map = (t_pixel **)malloc(sizeof(t_pixel*) * data->size_y + 1)))
		return (-1);
	while (coord.y < data->size_y)
	{
		data->map[coord.y] = NULL;
		if (!(data->map[coord.y] =
		(t_pixel *)malloc(sizeof(t_pixel) * data->size_x + 1)))
			return (-1);
		coord.x = 0;
		while (coord.x < data->size_x)
		{
			data->map[coord.y][coord.x].height = 0;
			data->map[coord.y][coord.x].new_x = 0;
			data->map[coord.y][coord.x].new_y = 0;
			coord.x++;
		}
		coord.y++;
	}
	return (0);
}
