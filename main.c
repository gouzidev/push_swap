#include "push_swap.h"

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

void sort_two(t_stack **head, char *msg)
{
	if ((*head)->n > (*head)->next->n)
		swap_stack(head, msg);
}

void sort_three(t_stack **head)
{
	if (!*head || !(*head)->next || !(*head)->next->next)
		return;
	if ((*head)->n < (*head)->next->n && (*head)->n > (*head)->next->next->n)
		reverse_rotate_stack(head, "rra");
	else if ((*head)->n > (*head)->next->n && (*head)->n < (*head)->next->next->n)
		swap_stack(head, "sa");
	else if ((*head)->n < (*head)->next->n && (*head)->next->n > (*head)->next->next->n)
		reverse_rotate_stack(head, "rra");
	else if ((*head)->n < (*head)->next->n && (*head)->next->n < (*head)->next->next->n)
	{
		swap_stack(head, "sa");
		rotate_stack(head, "ra");
	}
	else if ((*head)->n > (*head)->next->n && (*head)->next->n < (*head)->next->next->n)
	{
		swap_stack(head, "sa");
		reverse_rotate_stack(head, "rra");
	}
	else
		print_exit("Error\n");
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->n > max_node->n)
			max_node = stack;
		stack = stack->next;
	}
	return max_node;
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

void push_to_b(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*head;
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		i;
	int		mid;
	int		div;
	int		start;
	int		end;
	int		offset;
	int		arr_size;
	int		count;

	a = *stack_a;
	b = *stack_b;
	i = 1;
	give_index(a);
	arr = make_arr(a, &arr_size);
	i = 0;
	sort_arr(arr, arr_size);
	mid = arr_size / 2 - 1;
	div = arr[mid];
	offset = 2;
    end = mid + offset;
    start = mid - offset;
    int a_size = size(a);
    int index = 0;
	head = a;
	int flag;
	while (a)
	{
		if (a->n >= arr[start] && a->n <= arr[end])
		{
			push_a_to_b(&a, &b);
			if (b->n >= arr[mid])
				rotate_stack(&b, "rb");
		}
		else
		{
			flag = 0;
			index = 0;
			temp = a;
			while (temp)
			{
				if (temp->n >= arr[start] && temp->n <= arr[end])
				{
					while (index-- > 0)
						rotate_stack(&a, "ra");
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
			}
		}
		
	}
}

void set_up(t_stack **stack_a, t_data *data)
{
	give_index(*stack_a);
	data->arr = make_arr(*stack_a, &data->arr_size);
	sort_arr(data->arr, data->arr_size);
	data->mid = data->arr_size / 2 - 1;
	data->div = data->arr[data->mid];
	data->offset = 2;
    data->end = data->mid + data->offset;
    data->start = data->mid - data->offset;
	check_offset(&data->start, &data->end, data->offset, data->arr_size);
}

void push_B(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*temp;
    int index;
	int flag;
	
	while (*stack_a)
	{
		if ((*stack_a)->n >= data->arr[data->start] && (*stack_a)->n <= data->arr[data->end])
		{
			push_a_to_b(stack_a, stack_b);
			if ((*stack_b)->n >= data->arr[data->mid])
				rotate_stack(stack_b, "rb");
		}
		else
		{
			flag = 0;
			index = 0;
			temp = *stack_a;
			while (temp)
			{
				if (temp->n >= data->arr[data->start] && temp->n <= data->arr[data->end])
				{
					while (index-- > 0)
						rotate_stack(stack_a, "ra");
					push_a_to_b(stack_a, stack_b);
					flag = 1;
					break;
				}
				temp = temp->next;
				index++;
			}
			if (flag == 0)
				update_offset(&data->start, &data->end, data->offset, data->arr_size);
		}
		
	}
	give_index(*stack_b);

}

void push_A(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack *max_node;
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		max_node = find_max(b);
		if (max_node->i > data->mid)
		{
			while (b != max_node)
				reverse_rotate_stack(&b, "rrb");
			push_b_to_a(&a, &b, "pa");
		}
		else
		{
			while (b != max_node)
				rotate_stack(&b, "rb");
			push_b_to_a(&a, &b, "pa");
		}
	}
	*stack_b = b;
	*stack_a = a;
}

int	is_stack_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->n < head->next->n)
			return 0;
		head = head->next;
	}
	return 1;
}

int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	t_data data;
	t_stack *max_node;
	
	int		i;
	i = 0;
	b = NULL;
	a = parse(ac, av);
	set_up(&a, &data);	

	if (is_stack_sorted(a))
		return 0;
	if (size(a) == 2)
		sort_two(&a, "sa");
	if (size(a) == 3)
		sort_three(&a);
	else
	{
		push_B(&a, &b, &data);
		print_stack(b);
		print_array(data.arr, data.arr_size);
		print_info(data);
		printf("done\n");
		exit(0);
		push_A(&a, &b, &data);
	}
	printf("a -> \n");
	print_stack(a);
	printf("b -> \n");
	print_stack(b);

}
