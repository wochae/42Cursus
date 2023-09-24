/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:43:40 by wochae            #+#    #+#             */
/*   Updated: 2022/07/16 19:43:41 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
	int				index;
}	t_node;

typedef struct s_list {
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_list;

typedef struct s_lists {
	t_list	*a;
	t_list	*b;
}	t_lists;

t_node		*make_node(int num);
t_list		*init_list(void);
t_list		*input(int ac, char *av[]);
int			is_sorted(t_list *list);
void		sort_small(t_lists *lists);
void		sort_large(t_lists *lists);
int			is_rotate(t_list *list, int standard);
int			get_top(t_list *list);
int			ft_isnum(const char *s);
long long	ft_atoll(const char *str);
int			ft_numlen(long long n);
void		error_exit(void);
void		free_t_lists(t_lists *lists);
void		push(t_list *list, t_node *node);
void		rotate(t_list *list);
void		sa(t_lists *lists, int isChecker);
void		sb(t_lists *lists, int isChecker);
void		ss(t_lists *lists, int isChecker);
void		pa(t_lists *lists, int isChecker);
void		pb(t_lists *lists, int isChecker);
void		ra(t_lists *lists, int isChecker);
void		rb(t_lists *lists, int isChecker);
void		rr(t_lists *lists, int isChecker);
void		rra(t_lists *lists, int isChecker);
void		rrb(t_lists *lists, int isChecker);
void		rrr(t_lists *lists, int isChecker);

#endif
