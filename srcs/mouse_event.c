/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:57:39 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:57:41 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_event(int key, int x, int y, t_fdf *data)
{
	if (key == SCROLL_UP)
		data->zoom++;
	if (key == SCROLL_DOWN)
		data->zoom--;
	draw_map(data);
	return (0);
}
