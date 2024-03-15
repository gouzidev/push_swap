#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

typedef struct s_stack {
    struct s_stack *next;
    int n;
}   t_stack;

/* split.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **res, int w);
int	count_words(char const *s1, char c);
char	**handle_null_malloc(char const *s, char c);
char	**ft_split(char const *s, char c);
void check_format(char *s);

void print_exit(char *msg);


#endif


