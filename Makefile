NAME = fdf 


CC = GCC
CFLAGS =  -g
CPPFLAGS = -I ./includes -I ./libft -I ./minilibx_macos

LIB = libft/libft.a
MLIB = minilibx_macos/
MINILIB = $(addprefix $(MLIB),libmlx.a)
OBJ_DIR = ./objs/
SRC_DIR = ./srcs/

SRC = main.c \
	  draw_tools.c \
	  drawing.c \
	  3d_to_2d.c \
	  parsing.c \
	  menu.c \
	  menu2.c \
	  events.c \
	  free_and_exit.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


all:$(LIB) $(MINILIB) $(NAME)


$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(CPPFLAGS) -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit -L ./libft -l ft $(SRCS) -o $(NAME)

$(LIB):
		make -C libft/

$(MINILIB):
		make -C minilibx_macos/

clean:
		rm -rf $(OBJ)
		make -C libft clean
		make -C $(MLIB) clean

fclean:clean
		rm -rf $(NAME)
		make -C libft fclean
		make -C $(MLIB) clean

re:fclean
		make all


.PHONY: clean fclean re all
.SILENT: all clean fclean re $(LIB) $(MINILIB)
