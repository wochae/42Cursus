/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:43:20 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:43:21 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup_and_indexing(t_list *a, t_node *node)
{
	t_node	*head;

	if (a->size == 0)
		return (0);
	head = a->top;
	while (1)
	{
		if (head->num < node->num)
			node->index++;
		else if (head->num > node->num)
			head->index++;
		else
			return (1);
		head = head->next;
		if (head == a->top)
			break ;
	}
	return (0);
}

static void	check_input(const char *s, t_list *a)
{
	long long	num;
	t_node		*new_node;

	num = ft_atoll(s);
	if (!(ft_isnum(s)))
		error_exit();
	if (num > 2147483647 || num < -2147483648)
		error_exit();
	new_node = make_node((int)num);
	if (check_dup_and_indexing(a, new_node))
		error_exit();
	push(a, new_node);
	rotate(a);
}

static void	split_input_str(const char *s, t_list *a)
{
	char	**sp;
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		error_exit();
	sp = ft_split(s, ' ');
	if (!sp)
		exit(1);
	i = 0;
	while (sp[i] != NULL)
	{
		check_input(sp[i], a);
		free(sp[i]);
		i++;
	}
	free(sp);
}

t_list	*input(int ac, char *av[])
{
	t_list	*a;
	int		i;

	i = 1;
	a = init_list();
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			split_input_str(av[i], a);
		else
			check_input(av[i], a);
		i++;
	}
	return (a);
}
