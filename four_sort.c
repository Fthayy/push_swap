#include "push_swap.h"

t_holder *four_sort(t_holder *hold)
{
    hold = pb(hold);
    hold->a = three_sort(hold->a);
    
    if (hold->b->nb < hold->a->nb)
        hold = pa(hold);
    else if (hold->b->nb > hold->a->nb && hold->b->nb < hold->a->next->nb)
    {
        ra(hold->a);
        hold = pa(hold);
        hold->a = rra(hold->a);
    }
    else if (hold->b->nb > hold->a->next->nb && hold->b->nb < hold->a->next->next->nb)
    {
        hold->a = rra(hold->a);
        hold = pa(hold);
        ra(hold->a);
        ra(hold->a);
    }
    else if(hold->b->nb > hold->a->next->next->nb)
    {
        hold = pa(hold);
        ra(hold->a);
    }
    return (hold);
}