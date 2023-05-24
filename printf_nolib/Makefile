NAME = libftprintf.a

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c \
	   ft_putadd.c ft_putunbr.c ft_puthexnbr.c \
	   ft_printf.c ft_strlen.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ./ft_printf.h
	ar rcs $(NAME) $(OBJS) 

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all bonus clean fclean re
