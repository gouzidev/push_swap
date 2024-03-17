CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
LEAK = -fsanitize=address

SRCS = main.c split.c helper.c verify.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC)  $^ -o $(NAME)
	rm -rf $(OBJS)

%o:%c
	$(CC)  -c $< 
re:	fclean all

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)