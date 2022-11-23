#include "libft/libft.h"
#include <stdio.h>
#include "push_swap.h"

char *get_numbers(char **av)
{ 
    int i;
    char **x;
    char *a;
    int j;
    i = 1;
    while (av[i])
    {
        printf("%s\n",av[i]);
        x = ft_split(av[i],' ');
        i++;
        j = 0;
        /*while(x[j])
        {
            printf("%s",x[j]);
            //ft_strjoin(a,x[j]);
            //ft_strjoin(a," ");
            j++;
        }*/
    }
    return (a); // a = "11 2 3 5 7 2 1 5 7 2"
}




int main(int ac,char **av)
{
    char *numbers;
    int size;
    t_stack *a_stack;
    int *numeros;
    if (ac > 1)
    {
        numbers = get_numbers(av);
        //size = find_size(av);
        //numeros = ft_prime_atoi(numbers);
        //a_stack = new_funct(numbers,size);
        //choose_method(size,a_stack);
    }
    return (0);
}
