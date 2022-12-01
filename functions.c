#include "push_swap.h"
#include <stdio.h>

void sa(t_stack *a)
{
    long int tmp;
    if(a && a->next != NULL)
    {
        tmp = a->nb;
        a->nb =a->next->nb;
        a->next->nb = tmp;
    }
    printf("sa\n");
}

void sb(t_stack *b)
{
    long int tmp;
    if(b && b->next != NULL)
    {
        tmp = b->nb;
        b->nb=b->next->nb;
        b->next->nb = tmp;
    }
    printf("sb\n");
}

void ss(t_stack *a)
{
    sa(a);
    sb(a);
    printf("ss\n");
}

void ra(t_stack *a)
{
    t_stack *tmp;
    t_stack *tmp2;
    long int hold = a->nb;
    tmp2 = a;
    tmp = a;
    while(tmp->next != NULL)
    {
        a->nb = tmp->next->nb;
        a = a->next;
        tmp = tmp->next;
    }
    a = tmp2;
    if (tmp->next == NULL)
        ft_lstlastnmb(a)->nb = hold;

    printf("ra\n");
}

void rb(t_stack *b)
{
    t_stack *tmp;
    t_stack *tmp2;
    long int hold = b->nb;
    tmp2 = b;
    tmp = b;
    while(tmp->next != NULL)
    {
        b->nb = tmp->next->nb;
        b = b->next;
        tmp = tmp->next;
    }
    b = tmp2;
    if (tmp->next == NULL)
        ft_lstlastnmb(b)->nb = hold;
    printf("rb\n");
}

void rr(t_stack *a,t_stack *b)
{
    rb(b);
    ra(a);
    printf("rr\n");
}

t_stack* rrb(t_stack *b)
{
    t_stack *ilk;
    t_stack *son;
    ilk = b;
    son = ft_lstlastnmb(b);
    son->prev->next = NULL;
    b = son;
    son->next = ilk;
    printf("rrb\n");
    return(b);
    
}
t_stack *rra(t_stack *a)
{
    t_stack *ilk;
    t_stack *son;
    ilk = a;
    son = ft_lstlastnmb(a);
    son->prev->next = NULL;
    a = son;
    son->next = ilk;
    printf("rra\n");
    return(a);
}

void rrr(t_stack *a,t_stack *b)
{
    rra(a);
    rrb(b);
    printf("rrr\n");
}

t_holder *pa(t_holder *hold)
{
    t_stack *tmp;
    t_stack *tmp2;
    tmp = hold->b->next;
    hold->b->next = NULL;
    if (hold->a_size == 0)
    {
        hold->a = hold->b;
        hold->b = tmp;
    }
    else
    {
        tmp2 = hold->a;
        hold->a = hold->b;
        hold->a->next = tmp2;
        hold->b = tmp;
    }
    hold->a_size += 1;
    hold->b_size -= 1;
    printf("pa\n");
    return(hold);
}

t_holder *pb(t_holder *hold)
{
    t_stack *tmp;
    t_stack *tmp2;
    tmp = hold->a->next;
    hold->a->next = NULL;
    if (hold->b_size == 0)
    {
        hold->b = hold->a;
        hold->a = tmp;
    }
    else
    {
        tmp2 = hold->b;
        hold->b = hold->a;
        hold->b->next = tmp;
        hold->a = tmp;
    }

    hold->a_size -= 1;
    hold->b_size += 1;
    printf("pb\n");
    return(hold);
}