/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/11 15:45:28 by vveyrat-     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/11 15:45:30 by vveyrat-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "define.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_line_draw
{
	int				diff_y;
	int				diff_x;
	int				orient_x;
	int				orient_y;
	int				e;
	int				e2;
}					t_line_draw;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_pixel
{
	int				no_height;
	double			height;
	double			new_x;
	double			new_y;
}					t_pixel;

typedef struct		s_fdf
{
	struct s_pixel	**map;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				bpp;
	int				s_l;
	int				endian;
	int				projection;
	int				speed;
	int				size_x;
	int				size_y;
	int				screen_max;
	int				filter;
	int				color;
	int				r;
	int				g;
	int				b;
	double			height;
	int				invert_height;
	double			zoom;
	double			x_move;
	double			y_move;
}					t_fdf;

int					read_map(t_fdf *fdf, int fd);
int					init_tab(t_fdf *data, char *read);
void				hud(t_fdf *data);
void				draw_line(t_fdf *fdf, t_coord p0, t_coord p1);
void				draw_map(t_fdf *data);
void				convertion(t_fdf *data, int y, int x, t_coord space);
void				iso_projection(t_fdf *data, int y, int x);
void				ortho_projection(t_fdf *data, int y, int x);
void				invert_height(t_fdf *data);
void				hud_text(t_fdf *data);
int					key_event(int key, t_fdf *data);
void				key_move(t_fdf *data, int key);
void				key_height(t_fdf *data, int key);
void				key_filter(t_fdf *data, int key);
void				key_color(t_fdf *data, int key);
void				key_projection(t_fdf *data, int key);
int					mouse_event(int key, int x, int y, t_fdf *data);
void				put_pixel(t_fdf *data, int x, int y);
int					free_and_escape(t_fdf *data);

#endif
