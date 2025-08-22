SRC = fractol.c ft_fractol.c ft_init.c ft_hook.c tools.c

OBJ = $(SRC:.c=.o)

MLX = minilibx-linux/libmlx.a

MLX_H = minilibx-linux/mlx.h

NAME = fractol

CC =	cc -Wall -Wextra -Werror
RM =	rm -f

%.o: %.c fractol.h $(MLX_H)
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(OBJ) $(MLX) -lX11 -lXext -o $(NAME)

$(MLX):
	make -C minilibx-linux

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
