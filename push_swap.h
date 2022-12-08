/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fay <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:37:14 by fay               #+#    #+#             */
/*   Updated: 2022/12/08 14:37:15 by fay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long int		nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_holder
{
	t_stack			*a;
	t_stack			*b;
	long			a_size;
	long			b_size;
}					t_holder;

typedef struct s_longest
{
	int				start;
	int				end;
	int				tmpend;
	int				tmpstart;
}					t_longest;

typedef struct s_location
{
	int				rank;
	int				tmp_rank;
	int				place;
	int				tmp_place;
	int				holdrank;
	int				holdplace;
}					t_location;

typedef struct s_numbers
{
	int				*numeros;
	int				*sortednumbers;
}					t_numbers;

t_holder			*pb(t_holder *hold);
t_holder			*pa(t_holder *hold);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
t_stack				*rrb(t_stack *b);
t_stack				*rra(t_stack *a);
t_holder			*rrr(t_holder *hold);
t_stack				*three_sort(t_stack *a);
t_holder			*four_sort(t_holder *hold);
t_stack				*two_sort(t_stack *a);
t_stack				*ft_lstlastnmb(t_stack *lst);
t_stack				*ft_lstnmb(int nbr);
int					*bubblesort(int *numeros, int size);
t_longest			find_longest(int *numeros, int size);
int					*ft_sort_number(int *numeros, int size);
t_location			findloc(int *sortednumbers, t_holder *hold, int size);
void				big_sort(t_holder *hold, t_numbers *num, int size,
						t_longest longest);
char				*get_numbers(char **av);
int					find_size(char **av);
t_stack				*ft_prev(t_stack *lst);

#endif
