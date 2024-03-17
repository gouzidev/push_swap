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
    int i;
}   t_stack;

/* main.c */
int ft_atoi(const char *str);
t_stack *new(int n);
void push(t_stack **head, t_stack *new);
void pop(t_stack **head);
t_stack *duplicate(t_stack *node);
t_stack *before_last(t_stack *head);
t_stack *last(t_stack *head);
int size(t_stack *stack);
int exists(t_stack *stack, t_stack *node);
void clear(t_stack **head);
void swap_stack(t_stack **head);
void push_b_to_a(t_stack **a, t_stack **b);
void push_a_to_b(t_stack **a, t_stack **b);
void rotate_stack(t_stack **stack);
void rotate_ab(t_stack **a, t_stack **b);
void reverse_rotate_stack(t_stack **stack);
void reverse_rotate_ab(t_stack **a, t_stack **b);
int *make_arr(t_stack *head, int *arr_size);
void sort_arr(int   *arr, int arr_size);
t_stack *parse(int ac, char *av[]);
void give_index(t_stack *head);

/* split.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **res, int w);
int	count_words(char const *s1, char c);
char	**handle_null_malloc(char const *s, char c);
char	**ft_split(char const *s, char c);
void check_format(char *s);

/* helper.c */
void print_exit(char *msg);
void print_array(int  *array, int arr_size);
void print_stack(t_stack *stack);
void fill_stack(t_stack **stack);

int is_empty(char   *s);
int valid(char *num);
#endif
