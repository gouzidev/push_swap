#include "push_swap.h"

int ft_atoi(const char *str)
{
	int	    i;
	int	    sign;
	long    res;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
        if (res > INT_MAX || (res * sign) < INT_MIN)
            print_exit("laaaarge number");
		i++;
	}
	return (res * sign);
}
t_stack *new(int n)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (new_node == 0)
        return (0);
    new_node->next = NULL;
    new_node->n = n;
    return (new_node);
}
void push(t_stack **head, t_stack *new)
{
    new->next = *head;
    *head = new;
}
void pop(t_stack **head)
{
    t_stack *temp;
    if (!*head)
        return;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}
t_stack *dup(t_stack *node)
{
    t_stack *temp;

    if (!node)
        return (NULL);
    temp = new (node->n);
    return temp;
}
t_stack *before_last(t_stack *head)
{
    while (head && head->next && head->next->next)
        head = head->next;
    return head;
}
t_stack *last(t_stack *head)
{
    while (head && head->next)
        head = head->next;
    return head;
}
void fill_stack(t_stack **stack)
{
    push(stack, new (1));
    push(stack, new (2));
    push(stack, new (3));
    push(stack, new (4));
}
void print_stack(t_stack *stack)
{
    printf("---\n");
    while (stack)
    {
        printf("-> %d\n", stack->n);
        stack = stack->next;
    }
    printf("\n---\n");
}
void print_exit(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}
int valid(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    if (num[i] < '0' || num[i] > '9')
        return (0);
    while (num[i])
    {
        if (num[i] < '0' || num[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
int size(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}
int exists(t_stack *stack, t_stack *node)
{
    t_stack *temp;

    temp = stack;
    while (temp)
    {
        if (temp->n == node->n)
            return (1);
        temp = temp->next;
    }
    return (0);
}
void clear(t_stack **head)
{
    t_stack *curr;
    t_stack *temp;

    curr = *head;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
void swap_stack(t_stack **head)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if ((*head) && (*head)->    next)
    {
        tmp1 = new ((*head)->n);
        pop(head);
        tmp2 = new ((*head)->n);
        pop(head);
        push(head, tmp1);
        push(head, tmp2);
    }
}
// void swap_stack_ab(t_stack **a, t_stack **b)
// {
//     t_stack *tmp1;
//     t_stack *tmp2;
//     if ((*a) && (*a)->next)
//     {
//         tmp1 = new ((*a)->n);
//         pop(a);
//         tmp2 = new ((*a)->n);
//         pop(a);
//         push(a, tmp1);
//         push(a, tmp2);
//     }
// }
void push_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (!a || !b)
    {
        printf("Error\n");
        exit(1);
    }
    if (*b)
    {
        temp = dup(*b);
        pop(b);
        push(a, temp);
    }
}
void push_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (!a || !b)
    {
        printf("Error\n");
        exit(1);
    }
    if (*a)
    {
        temp = dup(*a);
        pop(a);
        push(b, temp);
    }
}
void rotate_stack(t_stack **stack)
{
    t_stack *last_a;
    t_stack *new_head;

    if (!stack || !*stack)
        return;
    new_head = (*stack)->next;
    last_a = last(*stack);
    if (last_a)
        last_a->next = *stack;
    (*stack)->next = NULL;
    (*stack) = new_head;
}
void rotate_ab(t_stack **a, t_stack **b)
{
    t_stack *last_a;
    t_stack *last_b;
    t_stack *new_head_a;
    t_stack *new_head_b;

    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    new_head_a = (*a)->next;
    new_head_b = (*b)->next;
    last_a = last(*a);
    last_b = last(*b);
    if (last_a)
        last_a->next = *a;
    if (last_b)
        last_b->next = *b;
    (*a)->next = NULL;
    (*b)->next = NULL;
    (*a) = new_head_a;
    (*b) = new_head_b;
}
void reverse_rotate_stack(t_stack **stack)
{
    t_stack *before_last_node;
    t_stack *last_node;
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    before_last_node = before_last(*stack);
    last_node = before_last_node->next;

    last_node->next = *stack;
    before_last_node->next = NULL;
    *stack = last_node;
}
void reverse_rotate_ab(t_stack **a, t_stack **b)
{
    t_stack *before_last_node_a;
    t_stack *before_last_node_b;
    t_stack *last_node_a;
    t_stack *last_node_b;
    if (!a || !(*a) || !(*a)->next)
        return;
    if (!b || !(*b) || !(*b)->next)
        return;
    before_last_node_a = before_last(*a);
    before_last_node_b = before_last(*b);
    last_node_a = before_last_node_a->next;
    last_node_b = before_last_node_b->next;

    last_node_a->next = *a;
    last_node_b->next = *b;
    before_last_node_a->next = NULL;
    before_last_node_b->next = NULL;
    *a = last_node_a;
    *b = last_node_b;
}
int is_empty(char   *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
int *make_arr(t_stack *head, int *arr_size)
{
    int *arr;
    int i;

    *arr_size = size(head);
    arr = malloc((*arr_size + 1) * sizeof(int));
    i = 0;
    while (head && i < *arr_size)
    {
        arr[i++] = head->n;
        head = head->next;
    }
    i = 0;
    return arr;
}
void sort_arr(int   *arr, int arr_size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < arr_size)
    {
        j = 0;
        while (j < arr_size - 1)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
t_stack *parse(int ac, char *av[])
{
    t_stack *a;
    t_stack *node;
    char **split_arr;
    int i;
    int j;

    i = 1;
    a = NULL;
    while (i < ac)
    {
        j = 0;
        // check_format(av[i]);
        split_arr = ft_split(av[i], ' ');
        if (split_arr == NULL)
            print_exit("Error\n");
        while (split_arr && split_arr[j])
        {
            if (is_empty(split_arr[j]))
                print_exit("Error (empty)\n");
            if (!valid(split_arr[j]))
                print_exit("Error (not valid)\n");
            else
            {
                node = new (ft_atoi(split_arr[j]));
                if (!node || exists(a, node))
                    print_exit("Error");
                push(&a, node);
            }
            j++;
        }
        i++;
        free_all(split_arr, j);
    }
    
    return a;
}
int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    int *nums_arr;
    int i;
    int n;
    int mid;
    int div;
    int start;
    int end;
    int offset;
    int arr_size;

    i = 1;
    a = NULL;
    b = NULL;
    a = parse(ac, av);
    print_stack(a);
    nums_arr = make_arr(a, &arr_size);
    i = 0;
    sort_arr(nums_arr, arr_size);
    while (i < arr_size)
        printf(" %d  ", nums_arr[i++]);
    mid = arr_size / 2;
    div =  nums_arr[mid];
    offset =  arr_size / div;
    start =  mid + offset;
    end =  mid - offset;
    while (a)
    {
        n = a->n;
        if  (a->n >= nums_arr[start] && a->n <= nums_arr[end])
        {
            a = a->next;
            push_a_to_b(&a, &b);
            if (a && a->n  <  nums_arr[mid])
                rotate_stack(&b);
        }
        else
            rotate_stack(&a);
    }
    start = start + offset;
    end = end - offset;
    if (start >= arr_size)
        start = arr_size - 1;
    if (end <= 0)
        end = 0;
    print_stack(b);
}

// find the smallest 