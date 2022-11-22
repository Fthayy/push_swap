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
}                   t_stack;

typedef struct  s_list
{
    t_stack *a;
    t_stack *b;
    struct  s_list  *next;
     
}                   t_list;

#endif