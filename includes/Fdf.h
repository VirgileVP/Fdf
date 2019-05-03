#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_piexl
{
	int				height;
	int				new_x;
	int				new_y;
}					t_pixel;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**map; // change to tab/tab/struct_pixel
	int				size_x;
	int				size_y;
	int				wind_x; // change it to macro
	int				wind_y; // change it to macro
}					t_fdf;

int					read_map(t_fdf *fdf, int fd);
void				draw_line(t_fdf *fdf, t_coord p1, t_coord p2, int high);
void				draw_map(t_fdf *fdf, int **map);

#endif
