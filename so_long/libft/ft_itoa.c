/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:30:00 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:30:01 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int			count;
	long long	m;

	count = 0;
	m = n;
	if (m < 0)
	{
		count++;
		m *= -1;
	}
	while (m > 0)
	{
		count++;
		m /= 10;
	}
	return (count);
}

static void	digit_copy(char *ret, int n, int count)
{
	long long	m;

	m = n;
	if (m < 0)
	{
		*ret = '-';
		m *= -1;
	}
	*(ret + count--) = 0;
	while (m > 0)
	{
		*(ret + count) = m % 10 + 48;
		m /= 10;
		count--;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	char	*ret;

	if (n == 0)
	{
		ret = (char *)malloc(sizeof(char) * 1 + 1);
		*ret = '0';
		*(ret + 1) = 0;
	}
	else
	{
		count = digit_count(n);
		ret = (char *)malloc(sizeof(char) * digit_count(n) + 1);
		if (!ret)
			return (0);
		digit_copy(ret, n, count);
	}
	return (ret);
}
