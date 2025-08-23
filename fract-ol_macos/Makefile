MLX = mlx/libmlx.a
MLX_H = mlx/mlx.h

SRC = fractol.c ft_fractol.c ft_init.c ft_hook.c tools.c
OBJ = $(SRC:.c=.o)

NAME = fractol

CC = cc -Wall -Wextra -Werror
RM = rm -f

%.o: %.c fractol.h $(MLX_H)
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(OBJ) $(MLX) -framework OpenGL -framework AppKit -lm -o $(NAME)

$(MLX):
	make -C mlx

clean:
	make -C mlx clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all