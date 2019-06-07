#include "Fdf.h"

void		HUD_text(t_fdf *data)
{
	char	*speed;
	char	*filter;
	char	*invert;
	char	*projection;

	speed = ft_itoa(data->speed);
	if (data->filter == 0)
		filter = "no filter";
	if (data->filter == 1)
		filter = "just dot";
	if (data->filter == 2)
		filter = "vertical";
	if (data->filter == 3)
		filter = "horizontal";
	invert = (data->invert_height == 0) ? "No" : "Yes";
	if (data->projection == 1)
		projection = "Isometric";
	else
		projection = "Orthogonal";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, 0xcccccc, "Change filter : .");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 30, 0xcccccc, "Filter : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 90, 30, 0xcccccc, filter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 5, 0xcccccc, "Move and rotate speed : + -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 30, 0xcccccc, "Speed = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 330, 30, 0xcccccc, speed);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 610, 5, 0xcccccc, "Move : W A S D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 610, 30, 0xcccccc, "Rotate : Arrow keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 890, 5, 0xcccccc, "Ajust height : R F");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 890, 30, 0xcccccc, "Invert : I -> ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1040, 30, 0xcccccc, invert);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1200, 5, 0xcccccc, "Projection : P");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1200, 30, 0xcccccc, projection);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 80, 0xcccccc, "Zoom : scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 80, 0xcccccc, "Color : 1/2/3/4/5/6");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 105, 0xcccccc, "R=");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 270, 105, 0xcccccc, ft_itoa(data->r));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 310, 105, 0xcccccc, "G=");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 330, 105, 0xcccccc, ft_itoa(data->g));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 370, 105, 0xcccccc, "B=");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 390, 105, 0xcccccc, ft_itoa(data->b));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1200, 80, 0xcccccc, "Quit : ESC");
}

void		background(t_fdf *data)
{
	int		index;

	index = 0;
	while (index <= 4 * WIND_X * 150)
	{
		index += 4;
		data->image[index] = 40;
		data->image[index + 1] = 40;
		data->image[index + 2] = 40;
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

void		HUD(t_fdf *data)
{
	t_coord	p1;
	t_coord	p2;

	background(data);
}