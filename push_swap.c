#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"
char *get_numbers(char **av)
{ 
    int i;
    char **x;
    char *a;
    int j;

    a = "";
    j = 0;
    i = 1;
    while (av[i])
    {
        x = ft_split(av[i],' ');
        i++;
        j = 0;
        while(x[j])
        {
            a = ft_strjoin(a,x[j]);
            a = ft_strjoin(a," ");
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
    while (av[i])
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
    t_stack *tmp;

    tmp = lst;
    if(!lst)
        return NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*ft_lstnmb(int nbr)
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
    t_stack *hold;
    
    hold = lst;
	while ( hold->next->next != NULL)
	{
		hold = hold->next;
	}
	return (hold);
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

t_stack *new_funct(int *numbers,int size)
{
    int i;
    t_stack *c;
    t_stack *a;
    i = 0;
    a = ft_lstnmb(numbers[i]);
    while (size > 1)
    {
        i++;
        c = ft_lstnmb(numbers[i]);
        lstadd(&a,c);
        size--;
    }
    return (a);
}

void choose_method(int size,t_stack *a_stack,t_stack *b_stack,t_longest longest,int *numeros,int *sortednumbers)
{
    t_holder *hold;
    hold = malloc(sizeof(t_holder));
    hold->a = a_stack;
    hold->b = b_stack;
    hold->a_size= size;
    hold->b_size = 0;
    if (size == 2)
        two_sort(a_stack);
    else if (size == 3)
    {
        three_sort(hold);
    }
    else if (size == 4)
        four_sort(hold);
    else
       big_sort(hold,numeros,size,longest,sortednumbers);
        
}

int	*ft_prime_atoi(char *numbers,int size)
{ 
    int *numeros;
    char **tmp;
    int y;

    y = 0;
    numeros = malloc (sizeof(int)*size);
    tmp = ft_split(numbers,' ');
    while (tmp[y])
    {
        numeros[y] = ft_atoi(tmp[y]);
        y++;
    }
    return (numeros);
}

int main(int ac,char **av)
{
    char *numbers;
    int size;
    t_stack *a_stack;
    int *numeros;
    t_stack *b_stack;
    int *sortednumbers;
    t_longest longest;
    
    if (ac > 1)
    {
        size = find_size(av);
        numbers = get_numbers(av);
        numeros = ft_prime_atoi(numbers,size);
        longest = find_longest(numeros,size);
        a_stack = new_funct(numeros,size);
        b_stack = malloc(sizeof(t_stack));
        sortednumbers = BubbleSort(numeros,size);
        a_stack->prev = ft_lstlastnmb(a_stack);
        choose_method(size,a_stack,b_stack,longest,numeros,sortednumbers);
    }
    return (0);
}