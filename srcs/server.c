/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:27:00 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/20 23:27:14 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

pid_t	g_pid_cl;

static void	error_m(int error)
{
	if (error == 1)
	{
		ft_printf(LPCH"\nWrong format. Please try: ");
		ft_printf(BBBL"./server\n");
	}
	else if (error == 2)
		ft_printf(LPCH"\nCould'n send signal to client\n");
}

static void	send_sig_to_cl(int sig)
{
	if (kill(g_pid_cl, sig) == -1)
		error_m(2);
}

static void	handler_sig(int sig, siginfo_t *info_cl, void *var)
{
	static int	i;
	static char	c;

	(void)var;
	if (info_cl->si_pid)
	{
		g_pid_cl = info_cl->si_pid;
	}
	c |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		if (!c)
			send_sig_to_cl(SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		error_m(1);
		exit (1);
	}
	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(LGTV"PID: %d\n", (getpid()));
	while (1)
		pause();
	return (0);
}
