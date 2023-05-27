SERVER = server

CLIENT = client

LIBFT_DIR = libft

PRINTF_DIR = printf_nolib

LIBFT =  $(LIBFT_DIR)/libft.a

PRINTF =  $(PRINTF_DIR)/libftprintf.a

L_SRCS = $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putunbr.c ft_puthexnbr.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_dlstnew.c ft_dlstadd_back.c ft_dlstlast.c\
		ft_lstmap.c ft_contains_digit.c ft_dlstadd_front.c ft_reverse_tab.c ft_printarr.c )
		
L_OBJS =  $(L_SRCS:.c=.o)

PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, ft_printf.c ft_putadd.c ft_putchar.c ft_puthexnbr.c ft_putnbr.c ft_putstr.c \
			ft_putunbr.c ft_strlen.c )

PRINTF_OBJS =  $(PRINTF_SRCS:.c=.o)

CLIENT_SRCS = client.c aux_binary.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS = server.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CFLAGS = -I . 

all: $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS) $(LIBFT) $(PRINTF) minitalk.h
	gcc $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(CLIENT) : $(CLIENT_OBJS) $(LIBFT) $(PRINTF) minitalk.h
	gcc $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o : %.c
	gcc -c  $(CFLAGS) $< -o $@

$(LIBFT): $(L_OBJS)

$(PRINTF) : $(PRINTF_OBJS)

$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	@make -C $(PRINTF_DIR)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re