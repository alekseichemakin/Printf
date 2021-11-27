NAME	= libftprintf.a
CC		= gcc
INCL	= ./includes
CFLAGS 	= -Wall -Wextra -Werror -I $(INCL) -c

SRCS	=	ft_parser.c \
			ft_print_str.c \
			ft_print_char.c \
			ft_print_hex.c \
			ft_print_int.c \
			ft_print_pointer.c \
			ft_print_unsigned.c \
			ft_printf.c \
			ft_write.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(MAKE) all -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)

clean :
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean : clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re : fclean all
