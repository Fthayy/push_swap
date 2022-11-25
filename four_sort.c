#include "push_swap.h"

t_stack *four_sort(t_stack *a,t_stack *b)
{
    pa(a,b);
    printf("a:%ld\n",a->nb);
    a = three_sort(a);
    if (b->nb < a->nb)
        pb(a,b);
    if (b->nb > a->nb && b->nb < a->next->nb)
    {
        ra(a);
        pb(a,b);
        rra(a);
    }
    if (b->nb > a->next->nb && b->nb < a->next->next->nb)
    {
        rra(a);
        pb(a,b);
        ra(a);
    }
    if(b->nb > a->next->next->nb)
    {
        pb(a,b);
        ra(a);
    }
    return (a);
}