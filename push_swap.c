#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"
char *get_numbers(char **av)
{ 
    int i;
    char **x;
    char *a;
    int j;
    j = 0;
    i = 2;
    while (av)
    {
        x = ft_split(av[i],' ');
        i++;
        j = 0;
        while(x[j])
        {
            ft_strjoin(a,x[j]);
            ft_strjoin(a," ");
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
        x = ft_split(av[i],' ');
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

t_stack	*ft_lstlastnmb(t_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstnmb(long int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*ft_prev(t_stack *lst)
{
	while (lst != NULL && lst->next->next != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack *lstadd(t_stack **lst,t_stack *new)
{
    if (*lst == NULL)
        *lst =new;
    ft_lstlastnmb(*lst)->next = new;
    new->next = NULL;
    new->prev = ft_prev(*lst);
    return(*lst);
}

t_stack *new_funct(char *numbers,int size)
{
    int i;
    t_stack *b;
    t_stack *a;
    i = 2;
    a = ft_lstnmb(numbers[i]);
    while (size > 1)
    {
        b = ft_lstnmb(numbers[i]);
        lstadd(&a,b);
        size--;
    }
    return (a);
}

void choose_method(int size,t_stack *a_stack)
{
    t_stack *b_stack;

    if (size == 2)
        two_sort(a_stack);
    else if (size == 3)
        three_sort(a_stack);
    else if (size == 4)
        four_sort(a_stack,b_stack);
    else;

}
/*int	ft_prime_atoi(char *numbers)
{
    int *numeros;
    int i;
    int j;

    i = 0;
    j = 0;
    while (numbers[i])
    {
        while (numbers[i] != ' ')
            j++;
        
        if (numbers[i] == ' ')
            j++;            
    }
}*/

int main(int ac,char **av)
{
    char *numbers;
    int size;
    t_stack *a_stack;
    int *numeros;

    if (ac > 1)
    {
        numbers = get_numbers(av);
        size = find_size(av);
        //numeros = ft_prime_atoi(numbers);
        //a_stack = new_funct(numbers,size);
        //choose_method(size,a_stack);
    }
    return (0);
}
