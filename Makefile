CC = CC
CFLAGS = -Wall -Wextra -Werror
SERVER = server
NAME = push_swap
SRCS = push_swap.c\
		push_check.c\
		push_add.c\
		push_list.c\
		push_operations\
		swap.c\
		sort_1.c\
		sort_2.c\
		sort_3.c\
		sort_4.c\


OBJS = push_swap.o\
		push_check.o\
		push_add.o\
		push_list.o\
		push_operations.o\
		swap.o\
		sort_1.o\
		sort_2.o\
		sort_3.o\
		sort_4.o\

LIBFT = ./libft/libft.a
PATH_LIBFT = ./libft

all: $(NAME)

$(LIBFT): ${PATH_LIBFT}
	make -C ${PATH_LIBFT}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ${PATH_LIBFT}

fclean: clean
	$(RM) $(NAME)
	make fclean -C ${PATH_LIBFT}

re: fclean all

.PHONY: all clean fclean re