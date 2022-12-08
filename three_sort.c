/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:36:07 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 14:36:13 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*three_sort(t_stack *a)
{
	if (a->nb > a->next->nb && a->next->nb < a->next->next->nb
		&& a->nb > a->next->next->nb)
		ra(a);
	else if (a->nb > a->next->nb && a->next->nb < a->next->next->nb
		&& a->nb < a->next->next->nb)
		sa(a);
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb
		&& a->nb > a->next->next->nb)
		a = rra(a);
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb
		&& a->nb < a->next->next->nb)
	{
		a = rra(a);
		sa(a);
	}
	else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb)
	{
		ra(a);
		sa(a);
	}
	return (a);
}
