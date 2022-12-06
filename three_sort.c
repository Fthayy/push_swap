#include "push_swap.h"

t_stack *three_sort(t_holder *hold)
{
    if (hold->a->nb > hold->a->next->nb && hold->a->next->nb < hold->a->next->next->nb && hold->a->nb > hold->a->next->next->nb)
        ra(hold->a);
    else if (hold->a->nb > hold->a->next->nb && hold->a->next->nb < hold->a->next->next->nb && hold->a->nb < hold->a->next->next->nb)
        sa(hold->a);
    else if (hold->a->nb < hold->a->next->nb && hold->a->next->nb > hold->a->next->next->nb && hold->a->nb > hold->a->next->next->nb)
        hold->a = rra(hold);
    else if (hold->a->nb < hold->a->next->nb && hold->a->next->nb > hold->a->next->next->nb && hold->a->nb < hold->a->next->next->nb) 
    {
        hold->a = rra(hold);
        sa(hold->a);
    }
    else if (hold->a->nb > hold->a->next->nb && hold->a->next->nb > hold->a->next->next->nb)
    {
        ra(hold->a);
        sa(hold->a);
    }
    
    return (hold->a);
}