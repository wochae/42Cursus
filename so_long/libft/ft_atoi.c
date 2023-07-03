/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:28:48 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:28:51 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str && ((*str == '-') || (*str == '+')))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		ret = ret * 10 + (*str - 48);
		if (ret * sign > 2147483647)
			return (-1);
		else if (ret * sign < -2147483648)
			return (0);
		str++;
	}
	return (ret * sign);
}
