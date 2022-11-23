#include "push_swap.h"

t_stack *three_sort(t_stack *a)
{
    if(a->nb < a->next->nb && a->next->nb < a->next->next->nb)
        return (a);
    if (a->nb > a->next->nb && a->next->nb < a->next->next->nb)
        sa(a);
    if (a->nb < a->next->nb && a->next->nb > a->next->next->nb)
        rra(a);
    if (a->nb < a->next->nb && a->next->nb > a->next->next->nb)
    {
        ra(a);
        ra(a);
    }
    if (a->nb > a->next->nb && a->next->nb < a->next->next->nb)
        ra(a);
    if (a->nb > a->next->nb && a->next->nb > a->next->next->nb)
    {
        ra(a);
        ra(a);
    }
    return (a);
}