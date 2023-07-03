/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:32:40 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:32:41 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && i + ft_strlen(needle) - 1 < len)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			while (*(needle + j) && *(needle + j) == *(haystack + i + j))
			{
				j++;
			}
			if (!*(needle + j))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
