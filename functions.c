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
    if (b)
        b = b->next;
}

void rr(t_stack *a)
{
    rb(a);
    ra(a);
}

void rrb(t_stack *b)
{
    if (b)
        b = b->prev;
}
void rra(t_stack *a)
{
    if (a)
        a = a->prev;
}

void rrr(t_stack *a)
{
    rra(a);
    rrb(a);
}

void pb(t_stack *a,t_stack *b) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    if(a != NULL)
    {
        t_stack *tmp;
        t_stack *tmpprev;

        tmp = b;
        tmpprev = b->prev;
        b = a;
        b->next = tmp;
        b->prev = tmpprev;
        b->prev->next = b;
        tmpprev = a->prev;
        a = a->next;
        a->prev = tmpprev;
        a->prev->next = a;
        free(tmp);
        free(tmpprev);
    }
}

void pa(t_stack *a, t_stack *b) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    if(a != NULL)
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
}