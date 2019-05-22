#include "Fdf.h"

int		mouse_event(int key, int x, int y, t_fdf *data)
{
	if (key == SCROLL_UP)
		data->zoom++;
	if (key == SCROLL_DOWN)
		data->zoom--;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	HUD(data);
	convert_draw_map(data);
	return (0);
}