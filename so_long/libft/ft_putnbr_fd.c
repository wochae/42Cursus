/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:31:47 by wochae            #+#    #+#             */
/*   Updated: 2022/07/25 17:31:48 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr(long long n, int fd)
{
	char	buf;

	if (!(n / 10))
	{
		buf = n + 48;
		write(fd, &buf, 1);
	}
	else
	{
		buf = n % 10 + 48;
		write_nbr(n / 10, fd);
		write(fd, &buf, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	m;

	m = n;
	if (m < 0)
	{
		write(fd, "-", 1);
		m *= -1;
	}
	write_nbr(m, fd);
}
