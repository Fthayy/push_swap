#include "push_swap.h"

t_stack *four_sort(t_stack *a,t_stack *b)
{
    t_holder *hold;
    hold = malloc(sizeof(t_holder));
    hold->a = a;
    hold->b = b;
    hold = pb(hold->a,hold->b);
    hold->a = three_sort(hold->a);


    if (hold->b->nb < hold->a->nb)
        hold = pa(hold->a,hold->b);
    else if (hold->b->nb > hold->a->nb && hold->b->nb < hold->a->next->nb)
    {
        ra(hold->a);
        hold = pa(hold->a,hold->b);
        hold->a = rra(hold->a);
    }
    else if (hold->b->nb > hold->a->next->nb && hold->b->nb < hold->a->next->next->nb)
    {
        hold->a = rra(hold->a);
        hold = pa(hold->a,hold->b);
        ra(hold->a);
        ra(hold->a);
    }
    else if(hold->b->nb > hold->a->next->next->nb)
    {
        hold = pa(hold->a,hold->b);
        ra(hold->a);
    }
    return (a);
}