/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   which_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 14:57:51 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 14:57:53 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		key_event(int key, t_fdf *data)
{
	if (key == ESC)
		free_and_escape(data);
	if (key == LESS || key == MORE)
		key_move(data, key);
	if (key == W || key == A || key == S || key == D || key == Q || key == E
	|| key == Z || key == C)
		key_move(data, key);
	if (key == R || key == F || key == I)
		key_height(data, key);
	if (key == DOT)
		key_filter(data, key);
	if (key == P)
		key_projection(data, key);
	if (key >= KEY_1 && key <= KEY_6)
		key_color(data, key);
	return (0);
}
