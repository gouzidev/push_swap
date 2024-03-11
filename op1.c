#include "push_swap.h"

void sa(t_stack **head)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if ((*head) && (*head)->next)
    {
        tmp1 = new((*head)->n, (*head)->i);
        pop(head);
        tmp2 = new((*head)->n, (*head)->i);
        pop(head);
        push(head, tmp1);
        push(head, tmp2);
    }   
}
void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;
    if (!a || !b)
    {
        printf("Error\n");
        exit(1);
    }
    if (!is_empty(*b))
    {
        temp = dup(*b);
        pop(b);
        push(a, temp);
    }
}
void ra(t_stack **a)
{
    t_stack *last_a;
    t_stack *new_head;

    if (!a || !*a)
        return;
    new_head = (*a)->next;
    last_a = last(*a);
    last_a->next = *a;
    (*a)->next = NULL;
    (*a) = new_head;
}
void rra(t_stack **a)
{
    t_stack *before_last_a;
    t_stack *last_a;
    if (!a || !(*a) || !(*a)->next)
        return;
    before_last_a = before_last(*a);
    last_a = before_last_a->next;

    last_a->next = *a;
    before_last_a->next = NULL;
    *a = last_a;
}
