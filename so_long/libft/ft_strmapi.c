/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:32:31 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:32:32 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(ret + i) = (*f)(i, *(s + i));
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
