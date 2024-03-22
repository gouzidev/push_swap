CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
LEAK = -fsanitize=address

SRCS = main.c verify.c split.c helper.c linked_list.c operations.c
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