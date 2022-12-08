NAME = pushswap.a
LIBFT = ./libft/libft.a
SRCS		=	four_sort.c \
				functions.c \
				three_sort.c \
				two_sort.c \
				push_swap.c \
				push_swap_utils.c \
				big_sort.c \
				create.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror -g

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)
	gcc push_swap.c $(NAME)  $(LIBFT) -o push_swap 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean allx

