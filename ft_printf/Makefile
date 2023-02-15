NAME = libftprintf.a
SRCS = ft_pinhexnpr.c  ft_printf.c     ft_putchar.c    ft_putstr.c   wolf.c\
      ft_contdig.c    ft_prinptr.c      ft_putnbr.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
