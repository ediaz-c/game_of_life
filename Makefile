NAME		=		game_of_life
CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror -I./mlx -I./includes
RM			=		rm -f

MLX			=		./mlx/libmlx.a

# Path: srcs/
SRC			=		main.c map.c cells.c background.c game.c hooks.c print.c matrix.c
SRC_DIR		=		$(addprefix src/, $(SRC))

OBJ			=		$(SRC_DIR:.c=.o)

all: $(NAME)

.c.o:		%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@make -C ./mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -framework OpenGL -framework AppKit

clean:
	@make clean -C ./mlx
	@$(RM) $(OBJ)

fclean: clean
	@make clean -C ./mlx
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re