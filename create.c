/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:44:07 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 15:44:08 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	*get_numbers(char **av)
{
	int		i;
	char	**x;
	char	*a;
	int		j;

	a = "";
	j = 0;
	i = 1;
	while (av[i])
	{
		x = ft_split(av[i], ' ');
		i++;
		j = 0;
		while (x[j])
		{
			a = ft_strjoin(a, x[j]);
			a = ft_strjoin(a, " ");
			j++;
		}
	}
	return (a);
}

int	find_size(char **av)
{
	int		size;
	int		i;
	char	**x;
	int		j;

	size = 0;
	j = 0;
	i = 1;
	while (av[i])
	{
		x = ft_split(av[i], ' ');
		i++;
		j = 0;
		while (x[j])
		{
			j++;
			size++;
		}
	}
	return (size);
}

t_stack	*ft_lstlastnmb(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
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
	t_stack	*hold;

	hold = lst;
	while (hold->next->next != NULL)
	{
		hold = hold->next;
	}
	return (hold);
}
