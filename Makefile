CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
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
		push_outils.c\

SRCS_BONUS = checker.c\
				help.c\
				get_next_line.c\
				get_next_line_utils.c\

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
		push_outils.o\

OBJS_BONUS = checker.o\
				help.o\
				get_next_line.o\
				get_next_line_utils.o\

LIBFT = ./libft/libft.a
PATH_LIBFT = ./libft

all: $(NAME)

$(LIBFT): ${PATH_LIBFT}
	make -C ${PATH_LIBFT}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS)  $(filter-out push_swap.o, $(OBJS)) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

clean:
	rm -f *.o
	make clean -C ${PATH_LIBFT}

fclean: clean
	rm -rf $(NAME) $(BONUS)
	make fclean -C ${PATH_LIBFT}

re: fclean all

.PHONY: all clean fclean re bonus