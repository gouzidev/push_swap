#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

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
t_stack *new (int n)
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
    if (!new || !head)
        return;
	new->next = *head;
	*head = new;
    give_index(*head);
}
void ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}
void	pop(t_stack **head)
{
	t_stack	*temp;

	if (!*head)
		return ;
	temp = *head;
	*head = (*head)->next;
	ft_free(temp);
}
t_stack	*duplicate(t_stack *node)
{
	t_stack	*temp;

	if (!node)
		return (NULL);
	temp = new (node->n);
	if (temp == NULL)
		return NULL;
	return (temp);
}
t_stack	*before_last(t_stack *head)
{
	while (head && head->next && head->next->next)
		head = head->next;
	return (head);
}
t_stack	*last(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}
int	size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
int	exists(t_stack *stack, t_stack *node)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->n == node->n)
			return (1);
		temp = temp->next;
	}
	return (0);
}
void	clear(t_stack **head)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		ft_free(temp);
	}
}
void	swap_stack(t_stack **head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*head) && (*head)->next)
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
void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*b)
	{
		temp = duplicate(*b);
		pop(b);
		push(a, temp);
	}
	if (*a)
		give_index(*a);
	if (*b)
		give_index(*b);

}
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*a)
	{
		temp = duplicate(*a);
		pop(a);
		push(b, temp);
	}
	if (*a)
		give_index(*a);
	if (*b)
		give_index(*b);
}
void	rotate_stack(t_stack **stack)
{
	t_stack	*last_a;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_head = (*stack)->next;
	last_a = last(*stack);
	if (last_a)
		last_a->next = *stack;
	(*stack)->next = NULL;
	(*stack) = new_head;
	give_index(*stack);
}
void	rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*last_a;
	t_stack	*last_b;
	t_stack	*new_head_a;
	t_stack	*new_head_b;

	if (!a || !*a)
		return ;
	if (!b || !*b)
		return ;
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
void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*before_last_node;
	t_stack	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last_node = before_last(*stack);
	last_node = before_last_node->next;
	last_node->next = *stack;
	before_last_node->next = NULL;
	*stack = last_node;
	give_index(*stack);
}
void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*before_last_node_a;
	t_stack	*before_last_node_b;
	t_stack	*last_node_a;
	t_stack	*last_node_b;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (!b || !(*b) || !(*b)->next)
		return ;
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
int	*make_arr(t_stack *head, int *arr_size)
{
	int	*arr;
	int	i;

	*arr_size = size(head);
	arr = malloc((*arr_size + 1) * sizeof(int));
	i = 0;
	while (head && i < *arr_size)
	{
		arr[i++] = head->n;
		head = head->next;
	}
	i = 0;
	return (arr);
}
void	sort_arr(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size - 1)
		{
			if (arr[j] > arr[j + 1])
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
t_stack	*parse(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*node;
	char	**split_arr;
	int		i;
	int		j;

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
	return (a);
}
void print_info(int start, int end, int mid, int *arr, int arr_size, int div, int offset)
{
    printf("start  -> %d\n", start);
	printf("end  -> %d\n", end);
}
void check_offset(int *start, int *end, int offset, int arr_size)
{
    if (*end >= arr_size)
        *end = arr_size - 1;
    if (*start <= 0)
        *start = 0;
}
void update_offset(int *start, int *end, int offset, int arr_size)
{
	*end = *end + offset;
    *start = *start - offset;
	check_offset(start, end, offset, arr_size);
}
void	give_index(t_stack *head)
{
	t_stack	*curr;
	int		i;

	if (!head)
		return ;
	curr = head;
	i = 0;
	while (curr)
	{
		curr->i = i++;
		curr = curr->next;
	}
}
int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	t_stack	*head;
	int		*arr;
	int		i;
	int		mid;
	int		div;
	int		start;
	int		end;
	int		offset;
	int		arr_size;
	int		count;

	i = 1;
	a = NULL;
	b = NULL;
	a = parse(ac, av);
	give_index(a);
	arr = make_arr(a, &arr_size);
	i = 0;
	sort_arr(arr, arr_size);
	mid = arr_size / 2;
	div = arr[mid];
	offset = arr_size / mid;
	offset = arr_size / div;
    end = mid + offset;
    start = mid - offset;

    // print_info(start, end, mid, arr, arr_size, div, offset);
    int a_size = size(a);
    int index = 0;
	head = a;
	int flag;
	while (a)
	{
		if (a->n >= arr[start] && a->n <= arr[end])
		{
			push_a_to_b(&a, &b);
			if (b->n <= arr[mid])
				rotate_stack(&b);
		}
		else
		{
			printf("checking -> %d\n", a->n);
			flag = 0;
			index = 0;
			temp = a;
			while (temp)
			{
				if (temp->n >= arr[start] && temp->n <= arr[end])
				{
					while (index-- > 0)
						rotate_stack(&a);
					push_a_to_b(&a, &b);
					flag = 1;
					break;
				}
				temp = temp->next;
				index++;
			}
			if (flag == 0)
			{
				update_offset(&start, &end, offset, arr_size);
				print_info(start, end, mid, arr, arr_size, div, offset);
			}
		}
		if (flag == 0)
		{
			if (a)
				a = a->next;
			else
			{
				printf("head -> %d\n", head->n);
				break;
			}
		}
	}
	print_stack(b);
	print_stack(a);
}
