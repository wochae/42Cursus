/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:32:27 by wochae            #+#    #+#             */
/*   Updated: 2022/03/31 14:29:54 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	size_t	i;

	i = len;
	if (dst <= src)
	{
		return (ft_memcpy(dst, src, len));
	}
	if (dst == 0 && src == 0)
		return (NULL);
	while (i)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	return (dst);
}
