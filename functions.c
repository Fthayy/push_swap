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
}

void ss(t_stack *a)
{
    sa(a);
    sb(a);
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
}

void rr(t_stack *a,t_stack *b)
{
    rb(b);
    ra(a);
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
    return(a);
}

void rrr(t_stack *a,t_stack *b)
{
    rra(a);
    rrb(b);
}

void pb(t_stack *a,t_stack *b) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    if(a != NULL)
    {
        t_stack *tmp;
        t_stack *tmpprev;
        
    }
}

void pa(t_stack *a, t_stack *b) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    
        t_stack *tmp;
        t_stack *tmpprev;

        tmp = a;
        tmpprev = a->prev;
        a = b;
        a->next = tmp;
        a->prev = tmpprev;
        a->prev->next = a;
        tmpprev = b->prev;
        b = b->next;
        b->prev = tmpprev;
        b->prev->next = b;

        free(tmp);
        free(tmpprev);
}