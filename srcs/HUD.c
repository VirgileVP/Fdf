/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:53:10 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:53:12 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		put_text(t_fdf *data, int x, int y, char *str)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, TEXT, str);
}

void		print_color(t_fdf *data)
{
	char	*temp;

	temp = NULL;
	temp = ft_itoa(data->r);
	put_text(data, 250, 125, "R=");
	put_text(data, 270, 125, temp);
	ft_memdel((void**)&temp);
	temp = ft_itoa(data->g);
	put_text(data, 310, 125, "G=");
	put_text(data, 330, 125, temp);
	ft_memdel((void**)&temp);
	temp = ft_itoa(data->b);
	put_text(data, 370, 125, "B=");
	put_text(data, 390, 125, temp);
	ft_memdel((void**)&temp);
	put_text(data, 1200, 100, "Quit : ESC");
}

void		print_text(t_fdf *data)
{
	put_text(data, 5, 5, "Change filter : .");
	put_text(data, 5, 30, "Filter : ");
	put_text(data, 250, 5, "Move and rotate speed : + -");
	put_text(data, 250, 30, "Speed = ");
	put_text(data, 610, 5, "Move : W A S D");
	put_text(data, 610, 30, "Move diag : Q E Z C");
	put_text(data, 890, 5, "Ajust height : R F");
	put_text(data, 890, 30, "Invert : I");
	put_text(data, 1200, 5, "Projection : P");
	put_text(data, 5, 100, "Zoom : scroll");
	put_text(data, 250, 100, "Color : 1/2/3/4/5/6");
	print_color(data);
}

void		hud_text(t_fdf *data)
{
	char	*speed;
	char	*filter;
	char	*projection;

	speed = ft_itoa(data->speed);
	if (data->filter == 0)
		filter = "no filter";
	if (data->filter == 1)
		filter = "just dot";
	if (data->filter == 2)
		filter = "horizontal";
	if (data->filter == 3)
		filter = "vertical";
	if (data->projection == 1)
		projection = "Isometric";
	else
		projection = "Orthogonal";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 90, 30, TEXT, filter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 330, 30, TEXT, speed);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1200, 30, TEXT, projection);
	print_text(data);
	ft_memdel((void**)&speed);
}

void		hud(t_fdf *data)
{
	int		index;

	index = 0;
	while (index <= 4 * WIND_X * 150)
	{
		index += 4;
		data->image[index] = 40;
		data->image[index + 1] = 40;
		data->image[index + 2] = 43;
		data->image[index + 3] = 0;
	}
	while (index < 4 * (WIND_X * WIND_Y - 1))
	{
		index += 4;
		data->image[index] = 20;
		data->image[index + 1] = 20;
		data->image[index + 2] = 20;
		data->image[index + 3] = 0;
	}
}
