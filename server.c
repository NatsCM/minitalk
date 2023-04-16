/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:56 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/16 17:41:07 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(pid_t pid)
{
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

void	handler_sig(int sig, siginfo_t *info, void *var)
{
	static int	i;
	static char	c;

	(void)var;
	(void)info;
	c |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_SIGINFO;
	print_pid(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
