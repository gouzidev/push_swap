#include "push_swap.h"

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

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
		i++;
	}
	return (res * sign);
}
int is_empty(t_stack *head)
{
    if (head)
        return 0;
    return 1;
}
t_stack *new(int n) {
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == 0)
		return (0);
	new_node->next = NULL;
	new_node->n = n;
	return (new_node);
}
void	push(t_stack **head, t_stack *new)
{
	t_stack	*last;

    new->next = *head;
    *head = new;
}
void	pop(t_stack **head)
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
    temp = new(node->n);
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
    push(stack, new(1));
    push(stack, new(2));
    push(stack, new(3));
    push(stack, new(4));
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
void sa(t_stack **head)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if ((*head) && (*head)->next)
    {
        tmp1 = new((*head)->n);
        pop(head);
        tmp2 = new((*head)->n);
        pop(head);
        push(head, tmp1);
        push(head, tmp2);
    }   
}
void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (!a || !b)
    {
        printf("Error\n");
        exit(1);
    }
    if (!is_empty(*b))
    {
        temp = dup(*b);
        pop(b);
        push(a, temp);
    }
}
void ra(t_stack **a)
{
    t_stack *last_a;
    t_stack *new_head;

    if (!a || !*a)
        return;
    new_head = (*a)->next;
    last_a = last(*a);
    last_a->next = *a;
    (*a)->next = NULL;
    (*a) = new_head;
}
void rra(t_stack **a)
{
    t_stack *before_last_a;
    t_stack *last_a;
    if (!a || !(*a) || !(*a)->next)
        return;
    before_last_a = before_last(*a);
    last_a = before_last_a->next;

    last_a->next = *a;
    before_last_a->next = NULL;
    *a = last_a;
}
int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *node;
    char **arr;
    int i;
    int j;
    int n;

    i = 1;
    a = NULL;
    while (i < ac)
    {
        j = 0;
        arr = ft_split(av[i], ' ');
        while (arr && arr[j])
        {
            if (!valid(arr[j]))
                print_exit("Error\n");
            else
            {
                node = new(ft_atoi(arr[j]));
                if (!node)
                    print_exit("Error\n");
                push(&a, node);
            }
            j++;
        }
        i++;
        free_all(arr, j);
    }
    print_stack(a);
}