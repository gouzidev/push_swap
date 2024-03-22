#include "push_swap.h"

void ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

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

void	print_array(int *array, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
		printf(" %d  ", array[i++]);
	printf("\n");
}

void	print_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}
void	print_stack(t_stack *stack)
{
	printf("---\n");
	while (stack)
	{
		printf("-> %d [%d]\n", stack->n, stack->i);
		stack = stack->next;
	}
	printf("---\n");
}

void	fill_stack(t_stack **stack)
{
	push(stack, new (1));
	push(stack, new (2));
	push(stack, new (3));
	push(stack, new (4));
}

void print_info(t_data data)
{
    printf("start  -> %d\n", data.start);
	printf("end  -> %d\n", data.end);
	printf("mid  -> %d\n", data.mid);
	printf("div  -> %d\n", data.div);
	printf("offset  -> %d\n", data.offset);
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
