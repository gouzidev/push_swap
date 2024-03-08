#include "push_swap.h"
#include "libft/libft.h"


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
int main(int ac, char *av[])
{
    t_stack *head;
    int i;
    int n;

    i = 0;
    head = NULL;
    fill_stack(&head);
    print_stack(head);
    printf("size is -> %d\n", size(head));
}