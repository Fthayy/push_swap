#include "push_swap.h"

t_stack *two_sort(t_stack *a)
{
    printf("%ld-",a->nb);
    printf("%ld\n",a->next->nb);

    if(a->nb > a->next->nb)
        ra(a);
    
    printf("%ld-",a->nb);
    printf("%ld-",a->next->nb);
    return(a);
}