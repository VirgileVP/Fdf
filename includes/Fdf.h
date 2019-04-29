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

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**map;
	int				size_x;
	int				size_y;
}					t_fdf;

int					read_map(t_fdf *fdf, int fd);
void				draw_line(t_fdf *fdf, t_coord p1, t_coord p2);

#endif
