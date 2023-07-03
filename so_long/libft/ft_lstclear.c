/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:30:44 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:30:46 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_free;
	t_list	*seek;

	if (!del)
		return ;
	seek = *lst;
	while (seek)
	{
		to_free = seek;
		seek = seek->next;
		ft_lstdelone(to_free, del);
	}
	*lst = 0;
}
