#include "Fdf.h"

void		menu_up(t_fdf *data, t_coord p1, t_coord p2)
{
	int		count;

	count = 0;
	while (count <= 20)
	{
		p1.x = 0;
		p2.x = WIND_X;
		p1.y = 0 + count;
		p2.y = p1.y;
		draw_line(data, p1, p2, 0xa9a9d6);
		count++;
	}
	p1.x = 20;
	p2.x = WIND_X - 20;
	p1.y = 0 + count;
	p2.y = p1.y;
	draw_line(data, p1, p2, 0xffffff);
}

void		menu_down(t_fdf *data, t_coord p1, t_coord p2)
{
	int		count;

	count = 0;
	while (count <= 20)
	{
		p1.x = 0;
		p2.x = WIND_X;
		p1.y = WIND_Y - count;
		p2.y = p1.y;
		draw_line(data, p1, p2, 0xa9a9d6);
		count++;
	}
	p1.x = 20;
	p2.x = WIND_X - 20;
	p1.y = WIND_Y - count;
	p2.y = p1.y;
	draw_line(data, p1, p2, 0xffffff);
}
void		menu_left(t_fdf *data, t_coord p1, t_coord p2)
{
	int		count;

	count = 0;
	while (count <= 20)
	{
		p1.x = 0 + count;
		p2.x = p1.x;
		p1.y = 0;
		p2.y = WIND_Y;
		draw_line(data, p1, p2, 0xa9a9d6);
		count++;
	}
	p1.x = 0 + 20;
	p2.x = p1.x;
	p1.y = 21;
	p2.y = WIND_Y - 20;
	draw_line(data, p1, p2, 0xffffff);
}

void		menu_right(t_fdf *data, t_coord p1, t_coord p2)
{
	int		count;

	count = 0;
	while (count <= 20)
	{
		p1.x = WIND_X - count;
		p2.x = p1.x;
		p1.y = 0;
		p2.y = WIND_Y;
		draw_line(data, p1, p2, 0xa9a9d6);
		count++;
	}
	p1.x = WIND_X - 20;
	p2.x = p1.x;
	p1.y = 21;
	p2.y = WIND_Y - 20;
	draw_line(data, p1, p2, 0xffffff);
}

void		menu(t_fdf *data)
{
	t_coord	p1;
	t_coord	p2;

	menu_up(data, p1, p2);
	menu_down(data, p1, p2);
	menu_left(data, p1, p2);
	menu_right(data, p1, p2);
}