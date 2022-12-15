/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:38:57 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 14:38:58 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_holder*	ft_checker(t_location loc, t_holder *hold)
{
	int	i;

	i = 0;
	// printf("rank:%d\n",loc.holdrank);
	// printf("place:%d\n",loc.holdplace);
	if (loc.holdrank > (hold->b_size / 2) + 1)
	{
		while (i++ < (hold->b_size - loc.holdrank))
			hold->b = rrb(hold->b);
	}
	else
	{
		while (i++ < loc.holdrank)
			rb(hold->b);
	}
	i = 0;
	if (loc.holdplace > (hold->a_size / 2) + 1)
	{
		while (i++ < hold->a_size - loc.holdplace)
			hold->a = rra(hold->a);
	}
	else
	{
		while (i++ < loc.holdplace)
			ra(hold->a);
	}
	hold = pa(hold);
	return(hold);	
}

void	ft_pushbtoa(t_holder *hold, int *sortednumbers, int size)
{
	int			i;
	t_location	location;

	i = 0;
	while (hold->b_size > 0)
	{
		i = 0;
		location = findloc(sortednumbers, hold, size);
		hold = ft_checker(location, hold);
		// while (i++ < location.holdrank)
		// 	rb(hold->b);
		// i = 0;
		// while (i++ < location.holdplace)
		// 	ra(hold->a);
		// hold = pa(hold);
		// i = 0;
		// while (i++ < location.holdplace)
		// 	hold->a = rra(hold->a);
	}
}

int	atob(t_holder *hold, t_numbers *num, int tmpstart, int y)
{
	if (y == 0 && hold->a->nb < num->numeros[tmpstart])
	{
		ra(hold->a);
		y = 1;
	}
	else if (y == 1 && hold->a->nb > ft_lstlastnmb(hold->a)->nb)
	{
		ra(hold->a);
		y = 1;
	}
	else
		hold = pb(hold);
	return (y);
}

int	atobwhile(t_holder *hold, t_numbers *num, t_longest longest, int y)
{
	int	x;

	x = 0;
	if (hold->a->nb < num->numeros[longest.tmpstart])
	{
		y = atob(hold, num, longest.tmpstart, y);
	}
	else if (hold->a->nb == num->numeros[longest.tmpstart])
	{
		while (x < longest.tmpend - longest.tmpstart + 1)
		{
			ra(hold->a);
			x++;
			y = 1;
		}
	}
	else
		hold = pb(hold);
	return (y);
}

void	ft_lastoperation(t_holder *hold, t_numbers *num,int size)
{
	int i;
	i = 0;
	t_stack *tmp;
	tmp = hold->a;
	while (tmp->nb != num->sortednumbers[0])
	{
		i++;
		tmp = tmp->next;
	}
	if (i >= size / 2)
	{
		while (i++ < size)
			hold->a = rra(hold->a);
	}
	else
	{
		while (i-- > 0)
			ra(hold->a);
	}
}

void	big_sort(t_holder *hold, t_numbers *num, int size, t_longest longest)
{
	t_stack *tmp;
	int i;
	int y;
	i = 0;
	y = 0;
	tmp = hold->a;
	while (i < size - (longest.tmpend - longest.tmpstart))
	{
		y = atobwhile(hold, num, longest, y);
		i++;
	}
	ft_pushbtoa(hold, num->sortednumbers, size);
	ft_lastoperation(hold,num,size);
}

