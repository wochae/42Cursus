/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:00:57 by wochae            #+#    #+#             */
/*   Updated: 2022/03/23 21:14:35 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		if (s1[i] - s2[i] != 0)
			break ;
		if (n - 1 == i)
			break ;
		i++;
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
