/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:43:04 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:43:04 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_t_list(t_list *list)
{
	t_node	*tmp;

	if (list->size)
	{
		list->bottom->next = NULL;
		list->bottom = NULL;
		while (1)
		{
			tmp = list->top;
			list->top = list->top->next;
			free(tmp);
			if (!list->top)
				break ;
		}
	}
	free(list);
}

void	free_t_lists(t_lists *lists)
{
	free_t_list(lists->a);
	free_t_list(lists->b);
	free(lists);
}
