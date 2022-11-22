#include "push_swap.h"

void sa(t_list *list)
{
    long int tmp;
    if(list && list->next != NULL)
    {
        tmp = list->a->nb;
        list->a->nb =list->a->next->nb;
        list->a->next->nb = tmp;
    }
}

void sb(t_list *list)
{
    long int tmp;
    if(list && list->next != NULL)
    {
        tmp = list->b->nb;
        list->b->nb=list->b->next->nb;
        list->b->next->nb = tmp;
    }
}

void ss(t_list *list)
{
    sa(list);
    sb(list);
}

void ra(t_list *list)
{
    if (list->a)
        list->a = list->a->next;
}

void rb(t_list *list)
{
    if (list->b)
        list->b = list->b->next;
}

void rr(t_list *list)
{
    rb(list);
    ra(list);
}

void rrb(t_list *list)
{
    if (list->b)
        list->b = list->b->prev;
}
void rra(t_list *list)
{
    if (list->a)
        list->a = list->a->prev;
}

void rrr(t_list *list)
{
    rra(list);
    rrb(list);
}

void pb(t_list *list) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    long int tmp;
    long int tmpprev;
    if(list->a)
    {

        tmp = list->b;
        tmpprev = list->b->prev;
        list->b = list->a;
        list->b->next = tmp;
        list->b->prev = tmpprev;
        list->b->prev->next = list->b;
        tmpprev = list->a->prev;
        list->a = list->a->next;
        list->a->prev = tmpprev;
        list->a->prev->next = list->a;
    }
    free(tmp);
    free(tmpprev);
}

void pa(t_list *list) // A'nın ilk elemanını B'nin ilk elemanı haline getiriyoruz. B boşsa hic bisi yapma.
{
    long int tmp;
    long int tmpprev;
    if(list->a)
    {

        tmp = list->a;
        tmpprev = list->a->prev;
        list->a = list->b;
        list->a->next = tmp;
        list->a->prev = tmpprev;
        list->a->prev->next = list->a;
        tmpprev = list->b->prev;
        list->b = list->b->next;
        list->b->prev = tmpprev;
        list->b->prev->next = list->b;
    }
    free(tmp);
    free(tmpprev);
}

void 