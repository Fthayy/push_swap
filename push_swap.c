#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

char get_numbers(char **av)
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
        j = 0;
        while(x[j])
        {
            strjoin(a,x[j]);
            strjoin(a," ");
            j++;
        }
    }    
    return (a); // a = "11 2 3 5 7 2 1 5 7 2"
}

int find_size(char **av)
{ 
    int size;
    int i;
    char **x;
    int j;
    size = 0;
    j = 0;
    i = 1;
    while (av)
    {
        x = ft_split(av[i]," ");
        i++;
        j = 0;
        while(x[j])
        {
            j++;
            size++;
        }
    }    
    return (size); // a = "11 2 3 5 7 2 1 5 7 2"
}

t_stack	*ft_prev(t_stack *lst)
{
	while (lst != NULL && lst->next->next != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack lstadd(t_stack **lst,t_stack *new)
{
    if (*lst == NULL)
        *lst =new;
    ft_lstlast(*lst)->next = new;
    new->next = NULL;
    new->prev = ft_prev(*lst);
}


int main(int ac,char **av)
{
    char *numbers;
    int i;
    int size;
    t_stack *a;

    if (ac > 1)
    {
        numbers = get_numbers(av);
        size = find_size(av);
        a = malloc(sizeof(t_stack));
    }
    return (0);
}
