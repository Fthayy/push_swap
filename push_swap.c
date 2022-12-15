/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:37:02 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 14:37:03 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_stack	*lstadd(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	ft_lstlastnmb(*lst)->next = new;
	new->next = NULL;
	new->prev = ft_prev(*lst);
	return (*lst);
}

t_stack	*new_funct(int *numbers, int size)
{
	int		i;
	t_stack	*c;
	t_stack	*a;

	i = 0;
	a = ft_lstnmb(numbers[i]);
	while (size > 1)
	{
		i++;
		c = ft_lstnmb(numbers[i]);
		lstadd(&a, c);
		size--;
	}
	return (a);
}

void	choose_method(int size, t_holder *hold, t_longest longest,
		t_numbers *num)
{
	hold->a_size = size;
	hold->b_size = 0;
	if (size == 2)
		two_sort(hold->a);
	else if (size == 3)
	{
		three_sort(hold->a);
	}
	else if (size == 4)
		four_sort(hold);
	else
		big_sort(hold, num, size, longest);
}

int	*ft_prime_atoi(char *numbers, int size)
{
	int		*numeros;
	char	**tmp;
	int		y;

	y = 0;
	numeros = malloc(sizeof(int) * size);
	tmp = ft_split(numbers, ' ');
	while (tmp[y])
	{
		numeros[y] = ft_atoi(tmp[y]);
		y++;
	}
	return (numeros);
}

int	main(int ac, char **av)
{
	char		*numbers;
	int			size;
	t_holder	*hold;
	t_longest	longest;
	t_numbers	*num;
	hold = malloc(sizeof(t_holder));
	num = malloc(sizeof(t_numbers));
	if (ac > 1)
	{
		size = find_size(av);
		numbers = get_numbers(av);
		num->numeros = ft_prime_atoi(numbers, size);
		longest = find_longest(num->numeros, size);
		hold->a = new_funct(num->numeros, size);
		hold->b = malloc(sizeof(t_stack));
		num->sortednumbers = bubblesort(num->numeros, size);
		hold->a->prev = ft_lstlastnmb(hold->a);
		choose_method(size, hold, longest, num);
	}
	return (0);
}
