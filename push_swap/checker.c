/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:42:51 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:42:52 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	cmd_execute(t_lists *lists, const char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(lists, 1);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(lists, 1);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(lists, 1);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(lists, 1);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(lists, 1);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(lists, 1);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(lists, 1);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(lists, 1);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(lists, 1);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(lists, 1);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(lists, 1);
	else
		error_exit();
}

static void	execute(t_lists *lists)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		cmd_execute(lists, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
}

static void	check(t_lists *lists)
{
	if (is_sorted(lists->a) && lists->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	lists->b = init_list();
	execute(lists);
	check(lists);
	free_t_lists(lists);
	return (0);
}
