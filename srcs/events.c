#include "Fdf.h"

int		key_event(int key, t_fdf *data)
{
	if (key == ESCAPE)
		return (free_and_escape(data));
	return (0);
}