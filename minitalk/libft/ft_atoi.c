/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:16:33 by wochae            #+#    #+#             */
/*   Updated: 2022/03/26 16:45:41 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long		ret;

	ret = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (minus == 1
			&& ((ret == 922337203685477580 && *str > '7')
				|| ret > 922337203685477580) && ret < 1000000000000000000)
			return (-1);
		if (minus == -1
			&& ((ret == 922337203685477580 && *str > '8')
				|| ret > 922337203685477580) && ret < 1000000000000000000)
			return (0);
		ret *= 10;
		ret += (*str++ - '0');
	}
	return (ret * minus);
}
