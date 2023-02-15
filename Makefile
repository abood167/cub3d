NAME = cub3d

SRC = cub.c main.c keyevent.c utils.c parce.c parce2.c parce3.c parce4.c parce5.c utils2.c utils3.c utils4.c utils5.c utlils6.c events.c parce6.c read.c move_dowun.c read2.c raycast2.c raycast.c

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = mlx/libmlx.a

OBJ = $(SRC:.c=.o)

CC = gcc -g3 -O3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft ft_printf/libftprintf.a  -o cub3d


$(LIBFT):
	@make bonus -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX): 
	@make -C ./mlx
	cp $(MLX) .

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

 re: fclean all