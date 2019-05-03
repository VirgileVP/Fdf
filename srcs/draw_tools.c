#include "Fdf.h"
void        pixel_color(t_fdf *fdf, int x, int y , int high)
{
    if (high == 0)
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFFFFFF);
    else if (high > 0)
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFFFF00);
    else
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x00FFFF);
}

void		draw_diag2(t_fdf *fdf, t_coord start, t_coord end, int high)
{
	int		step;
	int		divis;
	int		sens;

	step = 0;
	sens = (end.x - start.x >= end.y - start.y) ? 1 : 0;
	divis = (end.x - start.x >= end.y - start.y) ? (end.x - start.x) / (end.y - start.y) : (end.y - start.y) / (end.x - start.x);
	while (start.x != end.x)
	{
		pixel_color(fdf, start.x, start.y, high);
		if (step == divis)
		{
			step = 0;
			if (sens == 1)
				start.x++;
			else
				start.y++;
		}
		if (sens == 1)
			start.y++;
		else
			start.x++;
		step++;
	}
}

void		draw_diag(t_fdf *fdf, t_coord p0, t_coord p1, int high)
{
	t_coord	start;
	t_coord	end;

	if (p0.x < p1.x)
	{
		start.x = p0.x;
		end.x = p1.x;
	}
	else
	{
		start.x = p1.x;
		end.x = p0.x;
	}
	if (p0.y < p1.y)
	{
		start.y = p0.y;
		end.y = p1.y;
	}
	else
	{
		start.y = p1.y;
		end.y = p0.y;
	}
	draw_diag2(fdf, start, end, high);
}

void		draw_line(t_fdf *fdf, t_coord p0, t_coord p1, int high)
{
	if (p0.x == p1.x)
	{
		while(p0.y != p1.y)
		{
			pixel_color(fdf, p0.x, p0.y, high);
			if (p0.y < p1.y)
				p0.y++;
			else
				p0.y--;
		}
	}
	else if (p0.y == p1.y)
	{
		while(p0.x != p1.x)
		{
			pixel_color(fdf, p0.x, p0.y, high);
			if (p0.x < p1.x)
				p0.x++;
			else
				p0.x--;
		}
	}
	else
		draw_diag(fdf, p0, p1, high);
}
