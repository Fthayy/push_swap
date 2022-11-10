#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"


ft_getav(char **av)
{
    int i;
    char *str;
    i = 1;
    while (av[i])
    {
        ft_strjoin(str,av[i]);
        ft_strjoin(str," ");
        i++;
    }
    return(str);
}
get_numbers(char **av)
{
    char *str
    char **arr;
    t_list *swap;
    int len;
    while(arr[len])
        len++;
    swap = calloc(1,sizeof(t_list);
    swap->stack_a = calloc(1,sizeof(int)*len);
    swap->stack_b = calloc(1,sizeof(int)*len);
    swap->sorted = calloc(1,sizeof(int)*len);
    swap->sorted_inx = calloc(1,sizeof(int)*len);
    swap->a_len = len;
    swap->b_len = len;
    str = ft_getav(**av);
    arr = ft_split(av,' ');
    {
        
    }
}

int main(int ac,char **av)
{
    char *a;
    int i;

    if (ac > 1)
    {
        get_numbers(char **av);
    return (0);
}