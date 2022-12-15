/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:15:27 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 17:15:28 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

int	find_biggest(t_holder *hold)
{
	int		biggest;
	t_stack	*tmp;
	int		x;

	x = 0;
	biggest = hold->a->nb;
	tmp = hold->a;
	while (tmp->next)
	{
		if (biggest < tmp->next->nb)
		{
			biggest = tmp->next->nb;
		}
		tmp = tmp->next;
	}
	tmp = hold->a;
	// printf("i:%d\n", biggest);
	while (x < 100)
	{
		if (biggest == ft_lstlastnmb(hold->a)->nb)
			return (0);
		if (biggest == tmp->nb)
			return (x + 1);
		x++;
		tmp = tmp->next;
	}
	// printf("check");
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
	ret = 50000;
	x = -1;
	i = 0;
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
	if (x == -1)
	{
		// printf("xy:%d\n",find_biggest(hold));
		return (find_biggest(hold));
	}
	return (x);
}

int	howbig(int size, int nb)
{
	if (nb > size / 2)
		return (size - nb);
	return (nb);
}

t_location	helper_func(t_holder *hold, t_location loc, int *snum, int size)
{
	int		i;
	int		z;
	int		x;
	t_stack	*tmp;

	x = hold->b_size;
	i = 0;
	tmp = hold->b;
	while (tmp != NULL)
	{
		z = howbig(hold->b_size, i);
		loc.rank = findrank(snum, tmp->nb);
		loc.place = howbig(hold->a_size, ft_loc(snum, hold, loc.rank, size));
		if ((z + loc.place < howbig(hold->b_size,loc.holdrank) + loc.tmp_place) || (loc.tmp_place + i == 0))
		{
			loc.holdplace = ft_loc(snum, hold, loc.rank, size);
			loc.holdrank = i;
			loc.tmp_rank = z;
			loc.tmp_place = loc.place;
			// printf("hold->b:%ld\n", hold->b->nb);
			// printf("locrank:%d\n", loc.holdrank);
			// printf("locplace:%d\n", loc.holdplace);
		}
		tmp = tmp->next;
		x--;
		i++;
	}
	// printf("locrank:%d\n", loc.holdrank);
	// printf("locplace:%d\n", loc.holdplace);
	return (loc);
}

t_location	findloc(int *sortednumbers, t_holder *hold, int size)
{
	t_location	location;

	location.rank = 0;
	location.tmp_rank = 0;
	location.place = 0;
	location.tmp_place = 0;
	location = helper_func(hold, location, sortednumbers, size);
	return (location);
}
