/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:43:51 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:43:52 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->next;
	list->bottom = list->bottom->next;
}

void	ra(t_lists *lists, int isChecker)
{
	rotate(lists->a);
	if (!isChecker)
		write(1, "ra\n", 3);
}

void	rb(t_lists *lists, int isChecker)
{
	rotate(lists->b);
	if (!isChecker)
		write(1, "rb\n", 3);
}

void	rr(t_lists *lists, int isChecker)
{
	rotate(lists->a);
	rotate(lists->b);
	if (!isChecker)
		write(1, "rr\n", 3);
}
