#include "push_swap.h"

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

void	pop(t_stack **head)
{
	t_stack	*temp;

	if (!*head)
		return ;
	temp = *head;
	*head = (*head)->next;
	ft_free(temp);
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
