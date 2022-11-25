#include "push_swap.h"

t_stack *three_sort(t_stack *a)
{
    printf("%ld-",a->nb);
    printf("%ld-",a->next->nb);
    printf("%ld\n",a->next->next->nb);


    if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb > a->next->next->nb)
        ra(a);
    else if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb < a->next->next->nb)
        sa(a);
    else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
        a = rra(a);
    else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb < a->next->next->nb) 
    {
        a = rra(a);
        sa(a);
    }
    else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb)
    {
        ra(a);
        sa(a);
    }

    printf("\ndis1:%ld",a->nb);
    printf(" \ndis2:%ld",a->next->nb);
    printf(" \ndis3:%ld",a->next->next->nb);
    return (a);
}