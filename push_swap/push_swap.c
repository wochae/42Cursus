/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:43:35 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:43:36 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_list(t_lists *lists)
{
	if (lists->a->size <= 5)
		sort_small(lists);
	else
		sort_large(lists);
}

int	main(int ac, char *av[])
{
	t_lists	*lists;

	if (ac < 2)
		return (0);
	lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
		exit(1);
	lists->a = input(ac, av);
	if (is_sorted(lists->a))
		exit(1);
	lists->b = init_list();
	sort_list(lists);
	free_t_lists(lists);
	return (0);
}
