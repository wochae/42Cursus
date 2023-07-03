/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:32:55 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:32:56 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		ret = malloc(1);
		*ret = 0;
		return (ret);
	}
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*(s + start + i) && i < len)
	{
		*(ret + i) = *(s + start + i);
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
