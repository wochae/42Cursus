/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:44:00 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:44:01 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_nodes(t_lists *lists)
{
	t_list	*a;

	a = lists->a;
	if (a->top->index > a->top->next->index)
		sa(lists, 0);
}

static void	sort_three(t_lists *lists, int first, int second, int third)
{
	if (first < second)
	{
		if (second > third && first < third)
		{
			rra(lists, 0);
			sa(lists, 0);
		}
		else if (second > third && first > third)
			rra(lists, 0);
	}
	else
	{
		if (second < third && first < third)
			sa(lists, 0);
		else if (second < third && first > third)
			ra(lists, 0);
		else if (second > third && first > third)
		{
			ra(lists, 0);
			sa(lists, 0);
		}
	}
}

static void	sort_three_nodes(t_lists *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->top->index;
	second = lists->a->top->next->index;
	third = lists->a->top->next->next->index;
	sort_three(lists, first, second, third);
}

static void	sort_more_nodes(t_lists *lists)
{
	t_list	*a;
	t_list	*b;
	int		a_min_index;

	a = lists->a;
	b = lists->b;
	a_min_index = 0;
	while (a->size > 3)
	{
		if (is_rotate(a, a->size / 2))
			while (a->top->index != a_min_index)
				ra(lists, 0);
		else
			while (a->top->index != a_min_index)
				rra(lists, 0);
		pb(lists, 0);
		a_min_index++;
	}
	sort_three_nodes(lists);
	if (b->top->index < b->top->next->index)
		rb(lists, 0);
	while (b->size)
		pa(lists, 0);
}

void	sort_small(t_lists *lists)
{
	if (lists->a->size < 2)
		return ;
	else if (lists->a->size == 2)
		sort_two_nodes(lists);
	else if (lists->a->size == 3)
		sort_three_nodes(lists);
	else
		sort_more_nodes(lists);
}
