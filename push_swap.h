#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_stack {
    struct s_stack *next;
    int n;
    int i;
}   t_stack;

/* split.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **res, int w);
int	count_words(char const *s1);
char	**handle_null_malloc(char const *s);
char	**ft_split(char const *s);
size_t	ft_strlen(const char *s);


#endif