/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:57:15 by wochae            #+#    #+#             */
/*   Updated: 2022/07/13 16:04:13 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

typedef struct sigaction	t_sigact;

typedef struct s_send_info
{
	char	*str;
	pid_t	server_pid;
}				t_send_info;

void	print_pid(void);
void	error_exit(char *str);
void	write_char(unsigned char character);
void	kill_wrapping(pid_t pid, int signal);

#endif
