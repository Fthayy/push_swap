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

void	ft_pushbtoa(t_holder *hold, int *sortednumbers, int size)
{
	int			i;
	t_location	location;

	i = 0;
	while (hold->b_size > 0)
	{
		i = 0;
		location = findloc(sortednumbers, hold, size);
		while (i++ < location.holdrank)
			rb(hold->b);
		i = 0;
		while (i++ < location.holdplace)
			ra(hold->a);
		hold = pa(hold);
		i = 0;
		while (i++ < location.holdplace)
			hold->a = rra(hold->a);
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

void	big_sort(t_holder *hold, t_numbers *num, int size, t_longest longest)
{
	t_stack	*tmp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tmp = hold->a;
	while (i < size - (longest.tmpend - longest.tmpstart))
	{
		y = atobwhile(hold, num, longest, y);
		i++;
	}
	ft_pushbtoa(hold, num->sortednumbers, size);
}
