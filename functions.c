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

t_stack* rrb(t_holder *hold)
{
    t_stack *ilk;
    t_stack *son;
    ilk = hold->b;
    son = ft_lstlastnmb(hold->b);
    son->prev->next = NULL;
    hold->b = son;
    hold->b->next = ilk;
    printf("rrb\n");
    return(hold->b);
    
}
t_stack *rra(t_holder *hold)
{
    // int holder;
    // int index;
    // t_stack *tmp;

    // tmp = hold->a;
    // holder = ft_lstlastnmb(hold->a)->nb;
    // index = hold->a_size;
    // while (index > 1)
    // {
    //     hold->a = ft_lstlastnmb(hold->a);
    //     hold->a->nb = hold->a->prev->nb;
    //     hold->a = hold->a->prev;
    //     index--;
    // }
    // hold->a = tmp;
    // hold->a->nb = holder;
    t_stack *ilk;
    t_stack *son;
    ilk = hold->a;
    son = ft_lstlastnmb(hold->a);
    son->prev->next = NULL;
    hold->a = son;
    hold->a->next = ilk;
    printf("rra\n");
    return (hold->a);
}

t_holder *rrr(t_holder *hold)
{
    hold->a = rra(hold);
    hold->b = rrb(hold);
    printf("rrr\n");
    return(hold);
}

t_holder *pa(t_holder *hold)
{
    t_stack *tmp;
    t_stack *tmp2;
    if (hold->b_size == 1)
    {
        hold->b->next = hold->a;
        hold->a = hold->b;
    }
    else
    {
        tmp = hold->b->next;
        hold->b->next->prev = ft_lstlastnmb(hold->b);
        hold->b->next = NULL;
        hold->b->prev = NULL;
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
            hold->a->next->prev = hold->a;
            hold->a->prev = ft_lstlastnmb(hold->a);
            hold->b = tmp;
        }
    }
    hold->b_size -= 1;
    hold->a_size += 1;
    printf("pa\n");
    return(hold);
}

t_holder *pb(t_holder *hold)
{
    t_stack *tmp;
    t_stack *tmp2;
    tmp = hold->a->next;
    hold->a->next->prev = ft_lstlastnmb(hold->a);
    hold->a->next = NULL;
    hold->a->prev = NULL;
    if (hold->b_size == 0)
    {
        hold->b = hold->a;
        hold->a = tmp;
    }
    else
    {
        tmp2 = hold->b;
        hold->b = hold->a;
        hold->b->next = tmp2;
        hold->b->next->prev = hold->b;
        hold->b->prev = ft_lstlastnmb(hold->b);
        hold->a = tmp;
    }
    hold->a_size -= 1;
    hold->b_size += 1;
    printf("pb\n");
    return(hold);
}