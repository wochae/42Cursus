/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:31:30 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:31:30 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			*(unsigned char *)(dst + i - 1)
				= *(const unsigned char *)(src + i - 1);
			i--;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
