#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

typedef struct s_stack
{
    long int    nb;
    struct  s_stack *next;
    struct  s_stack *prev;
}                  t_stack;

typedef struct s_holder
{
            t_stack *a;
            t_stack *b;
}               t_holder;

typedef struct s_longest
{
    int start;
    int end;
    int tmpend;
    int tmpstart;
}   t_longest;

t_holder*        pb(t_stack *a, t_stack *b);
t_holder*        pa(t_stack *a, t_stack *b);
void        sa(t_stack *a);
void        sb(t_stack *b);
void        ss(t_stack *a);
void        ra(t_stack *a);
void        rb(t_stack *b);
void        rr(t_stack *a,t_stack *b);
t_stack*        rrb(t_stack *b);
t_stack*        rra(t_stack *a);
void        rrr(t_stack *a,t_stack *b);
t_stack *three_sort(t_stack *a);
t_stack *four_sort(t_stack *a,t_stack *b);
t_stack *two_sort(t_stack *a);
t_stack	*ft_lstlastnmb(t_stack *lst);
t_stack	*ft_lstnmb(long int nbr);
int *BubbleSort(int *numeros,int size);
void find_longest(int *numeros,int size);
int *ft_sort_number(int *numeros,int size);

#endif