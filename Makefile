CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
LEAK = -fsanitize=address

SRCS = main.c split.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

%o:%c
	$(CC) $(FLAGS) -c $< 
re:	fclean all

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)