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

int	findrank(int *sortednumbers, int nb)
{
	int	i;

	i = 0;
	while (i < 500)
	{
		if (nb == sortednumbers[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_loc(int *sortednumbers, t_holder *hold, int rank, int size)
{
	int		ret;
	int		i;
	t_stack	*tmp3;
	int		x;

	size = 3;
	tmp3 = hold->a;
	ret = 500;
	i = 0;
	if (sortednumbers[rank] > ft_lstlastnmb(hold->a)->nb)
		return (hold->a_size);
	while (i < hold->a_size)
	{
		if (((findrank(sortednumbers, tmp3->nb) - rank < ret - rank))
			&& ((findrank(sortednumbers, tmp3->nb) - rank) > 0))
		{
			ret = findrank(sortednumbers, tmp3->nb);
			x = i;
		}
		i++;
		tmp3 = tmp3->next;
	}
	return (x);
}

int	howbig(int size, int nb)
{
	if (nb > size / 2)
		return (size - nb);
	return (nb);
}

t_location	findloc(int *sortednumbers, t_holder *hold, int size)
{
	t_stack		*tmp;
	t_location	location;
	int			x;
	int			i;
	int			z;

	i = 0;
	x = hold->b_size;
	tmp = hold->b;
	location.rank = 0;
	location.tmp_rank = 0;
	location.place = 0;
	location.tmp_place = 0;
	while (tmp != NULL)
	{
		z = howbig(hold->b_size, i);
		location.rank = findrank(sortednumbers, tmp->nb);
		location.place = howbig(hold->a_size, ft_loc(sortednumbers, hold,
					location.rank, size));
		if ((z + location.place < z + location.tmp_place) || (location.tmp_place
				+ z == 0))
		{
			location.holdplace = ft_loc(sortednumbers, hold, location.rank,
					size);
			location.holdrank = i;
			location.tmp_rank = z;
			location.tmp_place = location.place;
		}
		tmp = tmp->next;
		x--;
		i++;
	}
	return (location);
}

int	whichonebigger(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

void	pushelper(int rank, int place, t_holder *hold)
{
	int	i;

	i = 0;
	if (rank > place)
	{
		while (i < rank - place)
		{
			rra(hold->a);
		}
	}
	if (rank < place)
	{
		while (i < place - rank)
		{
			rrb(hold->b);
		}
	}
}

void	pushhelper2(int rank, int place, t_holder *hold)
{
	int	i;

	i = 0;
	if (rank > place)
	{
		while (i < rank - place)
		{
			ra(hold->a);
			i++;
		}
	}
	if (rank < place)
	{
		while (i < place - rank)
		{
			rb(hold->b);
			i++;
		}
	}
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
