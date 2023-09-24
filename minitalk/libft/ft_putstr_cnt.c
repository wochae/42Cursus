/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:55:40 by wochae            #+#    #+#             */
/*   Updated: 2022/04/29 17:55:40 by wochae           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_cnt(char *str)
{
	int	cnt;

	cnt = 0;
	if (str == NULL)
	{
		cnt = write(1, "(null)", 6);
		return (cnt);
	}
	while (*str)
	{
		cnt = cnt + write(1, str, 1);
		str++;
	}
	return (cnt);
}
