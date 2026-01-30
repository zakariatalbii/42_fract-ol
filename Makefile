MLX_H = 42_MLX/include/mlx.h

ifeq ($(shell uname -s), Linux)
	MLX_I = -I42_MLX/include -D X11=42
	MLX_L = 42_MLX/lib/linux/libmlx.a
	LIBS = -lX11 -lXext -lm
else
	MLX_I = -I42_MLX/include -D X11=0
	MLX_L = 42_MLX/lib/macOS/libmlx.a
	LIBS = -lm
endif

INCLUDE = -Iinclude

HEADER = include/fractol.h

SRC = src/fractol.c src/ft_fractol.c src/ft_init.c src/ft_hook.c src/tools.c

OBJ = $(SRC:.c=.o)

NAME = fractol

CC = cc -Wall -Wextra -Werror -Wno-incompatible-pointer-types

RM = rm -f

%.o: %.c $(HEADER) $(MLX_H)
	$(CC) -c $< $(INCLUDE) $(MLX_I) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INCLUDE) $(MLX_I) $(MLX_L) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all