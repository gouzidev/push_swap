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

t_stack	*new(int n)
{
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

void fill_stack(t_stack **stack)
{
    push(stack, new(7));
    push(stack, new(2));
    push(stack, new(6));
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("-> %d\n", stack->n);
        stack = stack->next;
    }

}

int valid(char *num)
{
    int i;

    i = 0;
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
int main2(int ac, char *av[])
{
    t_stack *head;
    int i;
    int n;

    i = 1;
    head = NULL;
    while (i < ac)
    {
        if (valid(av[i]))
            push(&head, new(ft_atoi(av[i])));
        i++;
    }
    // fill_stack(&head);
    print_stack(head);
    // printf("size is -> %d\n", size(head));
}
int main(int ac, char *av[])
{
    main2(ac, av);
    system("leaks a.out");
}