#include "push_swap.h"

void	swap_stack(t_stack **head, char *msg)
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
	printf("%s\n", msg);

}
void	push_b_to_a(t_stack **a, t_stack **b, char *msg)
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
    printf("%s\n", msg);

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
	printf("pb\n");
}
void	rotate_stack(t_stack **stack, char *msg)
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
	printf("%s\n", msg);
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
void	reverse_rotate_stack(t_stack **stack, char *msg)
{
	t_stack	*last_node;
	t_stack *new_head;
	t_stack	*head;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	new_head = (*stack)->next;
	last_node = last(*stack);
	last_node->next = head;
	head->next = NULL;
	*stack = new_head;
	give_index(*stack);
	printf("%s\n", msg);
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
