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