#include "Fdf.h"

void        pixel_color(t_fdf *fdf, int x, int y , unsigned long high)
{
    if (high == 0)
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFFFFFF);
    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, high);
}

void		draw_diag2(t_fdf *fdf, t_coord start, t_coord end, unsigned long high)
{
	int		step;
	int		divis;
	int		sens;

	step = 0;
	sens = (end.x - start.x >= end.y - start.y) ? 1 : 0;
	divis = (end.x - start.x >= end.y - start.y) ? (end.x - start.x) / (end.y - start.y) : (end.y - start.y) / (end.x - start.x);
	printf("divis = %d\n", divis);
	while (start.x != end.x)
	{
		pixel_color(fdf, start.x, start.y, high);
		printf("x = %d | y = %d\n", start.x, start.y);
		if (step == divis)
		{
			step = 0;
			if (sens == 1)
				start.y++;
			else
				start.x++;
		}
		if (sens == 1)
			start.x++;
		else
			start.y++;
		step++;
	}
}

void		draw_diag(t_fdf *fdf, t_coord p0, t_coord p1, unsigned long high)
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

void		draw_line(t_fdf *fdf, t_coord p0, t_coord p1, unsigned long high)
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
/*
void		draw_line(t_fdf *fdf, t_coord p0, t_coord p1, unsigned long high)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	temp;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	x = p0.x;
	y = p0.y;
	temp = 2 * dy - dx;
	while(x <= p1.x)
	{
		if (temp >= 0)
		{
			y = y + 1;
			temp = temp + 2 * dy - 2 * dx;
		}
		else
			temp = temp + 2 * dy;
		pixel_color(fdf, x, y, high);
		x++;
    }
}
*/