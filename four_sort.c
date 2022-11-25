#include "push_swap.h"

t_stack *four_sort(t_stack *a,t_stack *b)
{
    t_holder *hold;
    hold = malloc(sizeof(t_holder));
    hold->a = a;
    hold->b = b;
    hold = pa(hold->a,hold->b);
    hold->a = three_sort(hold->a);
    printf("\ndis1:%ld",hold->a->nb);
    printf(" \ndis2:%ld",hold->a->next->nb);
    printf(" \ndis3:%ld",hold->a->next->next->nb);
    printf(" \ndis4:%p",hold->a->next->next->next);
    printf("\na:%ld\n",hold->a->nb);


    if (hold->b->nb < hold->a->nb)
        hold = pb(hold->a,hold->b);
    else if (hold->b->nb > hold->a->nb && hold->b->nb < hold->a->next->nb)
    {
        ra(hold->a);
        hold = pb(hold->a,hold->b);
        hold->a = rra(hold->a);
    }
    else if (hold->b->nb > hold->a->next->nb && hold->b->nb < hold->a->next->next->nb)
    {
        hold->a = rra(hold->a);
        hold = pb(hold->a,hold->b);
        ra(hold->a);
        ra(hold->a);
    }
    else if(hold->b->nb > hold->a->next->next->nb)
    {
        hold = pb(hold->a,hold->b);
        ra(hold->a);
    }
    printf("\ndisb1:%p",hold->b->next);
    printf("\ndis1:%ld",hold->a->nb);
    printf(" \ndis2:%ld",hold->a->next->nb);
    printf(" \ndis3:%ld",hold->a->next->next->nb);
    printf(" \ndis4:%ld",hold->a->next->next->next->nb);
    return (a);
}