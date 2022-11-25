NAME = pushswap.a

SRCS		=	four_sort.c \
				functions.c \
				three_sort.c \
				two_sort.c \
				push_swap.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror -g

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all