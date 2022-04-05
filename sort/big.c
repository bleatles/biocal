/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgijvasilcikov <georgijvasilcikov@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:48 by georgijvasi       #+#    #+#             */
/*   Updated: 2022/02/17 14:15:58 by georgijvasi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_b_to_a(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		push_down(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
	return (0);
}

void	move_b_to_a(t_all *all)
{
	int	i;

	min_max_med_b(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}

void	move_a_to_b(t_all *all)
{
	int	flag;
	int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			search_min_a_to_b(all);
		if (all->stack_a->index == min)
			push_down(all);
		else
			pb(all, 1);
	}
}

void	push_down(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

void	search_min_a_to_b(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->prev->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
}
