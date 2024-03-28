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

typedef struct s_data {
	int start;
	int end;
	int mid;
	int offset;
	int div;
	int arr_size;
	int	*arr;
	int orig_max;
	int curr_max_i;
	int	push_counter;
} t_data;

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
int *make_arr(t_stack *head, int *arr_size);
void sort_arr(int   *arr, int arr_size);
t_stack *parse(int ac, char *av[]);
void sort_two(t_stack **head, char *msg);
t_stack	*find_max_usin_arr(t_stack *stack, t_data *data);
t_stack	*find_min(t_stack *stack);

/* parse.c */
t_stack	*parse(int ac, char *av[]);

/* operations.c */
void	swap_stack(t_stack **head, char *msg);
void	push_b_to_a(t_stack **a, t_stack **b, char *msg);
void	push_a_to_b(t_stack **a, t_stack **b);
void	rotate_stack(t_stack **stack, char *msg);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rotate_stack(t_stack **stack, char *msg);
void	reverse_rotate_ab(t_stack **a, t_stack **b);



/* split.c */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_all(char **res);
int	count_words(char const *s1, char c, int	*len);
char	**handle_null_malloc(char const *s, char c,  int	*len);
char	**ft_split(char const *s, char c,  int	*len);
void check_format(char *s);

/* helper.c */
int	ft_atoi(const char *str);
void print_exit(char *msg);
void print_array(int  *array, int arr_size);
void print_stack(t_stack *stack);
void fill_stack(t_stack **stack);
void ft_free(void *ptr);

void update_offset(int *start, int *end, int offset, int arr_size);
void check_offset(int *start, int *end, int offset, int arr_size);
void print_info(t_data data);
void give_index(t_stack *head);

int is_empty(char   *s);
int valid(char *num);


/* linked_list.c */
t_stack *new (int n);
void	push(t_stack **head, t_stack *new);
void	pop(t_stack **head);
int	size(t_stack *stack);
t_stack	*duplicate(t_stack *node);
t_stack	*before_last(t_stack *head);
t_stack	*last(t_stack *head);
int	exists(t_stack *stack, t_stack *node);
void	clear(t_stack **head);

#endif
