/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:22:07 by wochae            #+#    #+#             */
/*   Updated: 2022/03/23 21:14:34 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (str[i] != 0 && i < len)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j]
				&& i + j < len && needle[j] != '\0'
				&& str[i + j] != 0)
				j++;
			if (needle[j] == '\0')
				return ((str + i));
		}
		i++;
	}
	return (NULL);
}
