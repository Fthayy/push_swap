#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

int get_numbers(char **av)
{
    int i;
    char **x;
    char *a;
    int j;
    j = 0;
    i = 1;
    while (av)
    {
        x = ft_split(av[i]," ");
        i++;
        while(x)
        {
            strjoin(a,x[j]);
            strjoin(a," ");
            j++;
        }
    }        
    return (a); // a = "11 2 3 5 7 2 1 5 7 2"
}

int main(int ac,char **av)
{
    char *a;
    int i;

    if (ac > 1)
    {
        get_numbers(av);
    }
    return (0);
}