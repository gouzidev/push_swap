#include "push_swap.h"

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

void print_info(int start, int end, int mid, int *arr, int arr_size, int div, int offset)
{
    printf("start  -> %d\n", start);
	printf("end  -> %d\n", end);
	printf("mid  -> %d\n", mid);
	printf("div  -> %d\n", div);
	printf("offset  -> %d\n", offset);
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
