#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIND_X 1400
# define WIND_Y 1000

# define ESCAPE 53

# define A 0
# define S 1
# define D 2
# define W 13

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define PLUS 69
# define MINUS 78

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_pixel
{
	int				height;
	int				new_x;
	int				new_y;
}					t_pixel;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_pixel	**map;
	int				size_x;
	int				size_y;
	int				screen_max;
}					t_fdf;

int					read_map(t_fdf *fdf, int fd);
int					key_event(int key, t_fdf *data);
void				menu(t_fdf *data);
void				draw_line(t_fdf *fdf, t_coord p1, t_coord p2, unsigned long high);
void				draw_map(t_fdf *fdf, t_pixel **map);
void				map_3d_to_2d(t_fdf *fdf);

int					free_and_escape(t_fdf *data);

#endif
