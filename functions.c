/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:44:38 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 15:44:40 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_stack *a)
{
	long int	tmp;

	if (a && a->next != NULL)
	{
		tmp = a->nb;
		a->nb = a->next->nb;
		a->next->nb = tmp;
	}
	printf("sa\n");
}

void	sb(t_stack *b)
{
	long int	tmp;

	if (b && b->next != NULL)
	{
		tmp = b->nb;
		b->nb = b->next->nb;
		b->next->nb = tmp;
	}
	printf("sb\n");
}

void	ss(t_stack *a)
{
	sa(a);
	sb(a);
	printf("ss\n");
}

void	ra(t_stack *a)
{
	t_stack		*tmp;
	t_stack		*tmp2;
	long int	hold;

	hold = a->nb;
	tmp2 = a;
	tmp = a;
	while (tmp->next != NULL)
	{
		a->nb = tmp->next->nb;
		a = a->next;
		tmp = tmp->next;
	}
	a = tmp2;
	if (tmp->next == NULL)
		ft_lstlastnmb(a)->nb = hold;
	printf("ra\n");
}

void	rb(t_stack *b)
{
	t_stack		*tmp;
	t_stack		*tmp2;
	long int	hold;

	hold = b->nb;
	tmp2 = b;
	tmp = b;
	while (tmp->next != NULL)
	{
		b->nb = tmp->next->nb;
		b = b->next;
		tmp = tmp->next;
	}
	b = tmp2;
	if (tmp->next == NULL)
		ft_lstlastnmb(b)->nb = hold;
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rb(b);
	ra(a);
	printf("rr\n");
}

t_stack	*rrb(t_stack *b)
{
	t_stack	*ilk;
	t_stack	*son;

	ilk = b;
	son = ft_lstlastnmb(b);
	son->prev->next = NULL;
	b = son;
	b->next = ilk;
	printf("rrb\n");
	return (b);
}

t_stack	*rra(t_stack *a)
{
	t_stack	*ilk;
	t_stack	*son;

	ilk = a;
	son = ft_lstlastnmb(a);
	son->prev->next = NULL;
	a = son;
	a->next = ilk;
	printf("rra\n");
	return (a);
}

t_holder	*rrr(t_holder *hold)
{
	hold->a = rra(hold->a);
	hold->b = rrb(hold->b);
	printf("rrr\n");
	return (hold);
}

t_holder	*pa(t_holder *hold)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (hold->b_size == 1)
	{
		hold->b->next = hold->a;
		hold->a = hold->b;
	}
	else
	{
		tmp = hold->b->next;
		hold->b->next->prev = ft_lstlastnmb(hold->b);
		hold->b->next = NULL;
		hold->b->prev = NULL;
		if (hold->a_size == 0)
		{
			hold->a = hold->b;
			hold->b = tmp;
		}
		else
		{
			tmp2 = hold->a;
			hold->a = hold->b;
			hold->a->next = tmp2;
			hold->a->next->prev = hold->a;
			hold->a->prev = ft_lstlastnmb(hold->a);
			hold->b = tmp;
		}
	}
	hold->b_size -= 1;
	hold->a_size += 1;
	printf("pa\n");
	return (hold);
}

t_holder	*pb(t_holder *hold)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	
	tmp = hold->a->next;
	hold->a->next->prev = ft_lstlastnmb(hold->a);
	hold->a->next = NULL;
	hold->a->prev = NULL;
	if (hold->b_size == 0)
	{
		hold->b = hold->a;
		hold->a = tmp;
	}
	else
	{
		tmp2 = hold->b;
		hold->b = hold->a;
		hold->b->next = tmp2;
		hold->b->next->prev = hold->b;
		hold->b->prev = ft_lstlastnmb(hold->b);
		hold->a = tmp;
	}
	hold->a_size -= 1;
	hold->b_size += 1;
	printf("pb\n");
	return (hold);
}
