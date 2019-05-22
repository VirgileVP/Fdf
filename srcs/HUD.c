#include "Fdf.h"

void		menu_up(t_fdf *data, t_coord p1, t_coord p2)
{
	p1.x = 2;
	p2.x = 300;
	p1.y = 3;
	p2.y = 3;
	draw_line(data, p1, p2, 0xffffff);
}

void		menu_down(t_fdf *data, t_coord p1, t_coord p2)
{
	p1.x = 2;
	p2.x = 300;
	p1.y = 120;
	p2.y = 120;
	draw_line(data, p1, p2, 0xffffff);
}
void		menu_left(t_fdf *data, t_coord p1, t_coord p2)
{
	p1.x = 2;
	p2.x = 2;
	p1.y = 3;
	p2.y = 120;
	draw_line(data, p1, p2, 0xffffff);
}

void		menu_right(t_fdf *data, t_coord p1, t_coord p2)
{
	p1.x = 300;
	p2.x = 300;
	p1.y = 3;
	p2.y = 120;
	draw_line(data, p1, p2, 0xffffff);
}

void		HUD(t_fdf *data)
{
	t_coord	p1;
	t_coord	p2;

	menu_up(data, p1, p2);
	menu_down(data, p1, p2);
	menu_left(data, p1, p2);
	menu_right(data, p1, p2);

	char	*speed;

	speed = ft_itoa(data->speed);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 20, 0xcccccc, "Move and rotate speed : + -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, 0xcccccc, "Speed = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 85, 5, 0xcccccc, speed);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 35, 0xcccccc, "Move : W A S D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 50, 0xcccccc, "Rotate : Arrow keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 65, 0xcccccc, "Ajust high : R F");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 80, 0xcccccc, "Zoom : scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 95, 0xcccccc, "Quit : ESC");
}