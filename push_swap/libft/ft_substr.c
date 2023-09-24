/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:31 by wochae            #+#    #+#             */
/*   Updated: 2022/03/23 16:10:42 by wochae           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	ourlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	ourlen = ft_strlen(s);
	if (start >= ourlen)
		return (ft_strdup(""));
	if (ourlen - start < len)
		len = ourlen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
