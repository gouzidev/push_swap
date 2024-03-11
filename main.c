#include "push_swap.h"

#include "push_swap.h"

void print_exit(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}
int	ft_3atwa(const char *str)
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
int is_empty(t_stack *head)
{
    if (head)
        return 0;
    return 1;
}
t_stack *new(int n, int i) {
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == 0)
		return (0);
	new_node->next = NULL;
	new_node->n = n;
    new_node->i = i;
	return (new_node);
}
int exists(t_stack *head, t_stack *node)
{
    if (!node)
        print_exit("please give a valid node");
    while (head)
    {
        if (head->n == node->n)
            return 1;
        head = head->next;
    }
    return (0);
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
    temp = new(node->n, node->i);
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
    push(stack, new(1, 0));
    push(stack, new(2, 1));
    push(stack, new(3, 2));
    push(stack, new(4, 3));
}
void print_stack(t_stack *stack)
{
    printf("---\n");
    while (stack)
    {
        printf("-> %d(%d)\n", stack->n, stack->i);
        stack = stack->next;
    }
    printf("\n---\n");

}
int valid(char *num)
{
    int i;

    i = 0;
    if (ft_strlen(num) > 11)
        return (0);
    if (num[i] == '-' || num[i] == '+')
        i++;
    if (num[i] < '0' || num[i] > '9')
    {
        printf("valid %s\n", num);
        return (0);
    }
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

// int verify(char *s)
// {
//     int i;

//     i = 0;
//     if (s[0] == ' ')
//         return 0;
//     if (s[0] == '+')
//     while (s[i])
//     {
//         if (s[i] < '9' )
//     }
// }

t_stack *parse(int  ac, char    *av[])
{
    t_stack *a;
    t_stack *node;
    int x;
    int y;
    int i;
    char **arr;

    x = 1;
    i = 0;
    a = NULL;
    while (x < ac)
    {
        y = 0;
        arr = ft_split(av[x]);
        while (arr && arr[y])
        {
            if (!valid(arr[y]))
                print_exit("Error\n");
            else
            {
                node = new(ft_3atwa(arr[y]), i++);
                if (!node || exists(a, node))
                    print_exit("Error\n");
                push(&a, node);
            }
            y++;
        }
        x++;
        free_all(arr, y);
    }
    return a;

}

int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (ac < 2)
        print_exit("please enter some numbers");
    a = parse(ac, av);
    print_stack(a);
}