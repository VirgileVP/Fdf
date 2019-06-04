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
# define BORDURE -10000

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define LESS 78
# define MORE 69
# define A 0
# define D 2
# define F 3
# define R 15
# define S 1
# define W 13
# define DOT 65
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

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
	int			x;
	int			y;
}					t_coord;

typedef struct		s_pixel
{
	int				no_high;
	double			height;
	double			new_x;
	double			new_y;
}					t_pixel;

typedef struct		s_fdf
{
	struct s_pixel	**map;
	void			*mlx_ptr;
	void			*win_ptr;
	int				speed;
	int				size_x;
	int				size_y;
	int				screen_max;
	int				filter;
	double			high;
	double			zoom;
	double			x_rot;
	double			y_rot;
	double			x_move;
	double			y_move;
}					t_fdf;

int					read_map(t_fdf *fdf, int fd);
void				HUD(t_fdf *data);
void				draw_line(t_fdf *fdf, t_coord p0, t_coord p1, unsigned long high);
void				draw_map(t_fdf *fdf, t_pixel **map);
void				convert_draw_map(t_fdf *data);
void				map_3d_to_2d(t_fdf *fdf);
int					key_event(int key, t_fdf *data);
int					mouse_event(int key, int x, int y, t_fdf *data);
void				pixel_color(t_fdf *data, int x, int y , unsigned long high)		;			
int					free_and_escape(t_fdf *data);

#endif
