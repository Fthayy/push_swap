#include "push_swap.h"

t_stack *three_sort(t_stack *a)
{
    printf("%ld-",a->nb);
    printf("%ld-",a->next->nb);
    printf("%ld\n",a->next->next->nb);


    if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb > a->next->next->nb)
        ra(a);
    if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb < a->next->next->nb)
        sa(a);
    if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
        rra(a);
    if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb < a->next->next->nb) 
    {
        rra(a);
        sa(a);
    }
    if (a->nb > a->next->nb && a->next->nb > a->next->next->nb)
    {
        ra(a);
        ra(a);
    }

    printf("%ld-",a->nb);
    printf("%ld-",a->next->nb);
    printf("%ld",a->next->next->nb);
    return (a);
}