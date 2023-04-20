/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:30 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/20 23:24:34 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	error_message(int error)
{
	if (error == 1)
		ft_printf(LPCH"\nWrong PID. Try again\n");
	else if (error == 2)
	{
		ft_printf(LPCH"\nWrong format. please try: ./client |");
		ft_printf(BBBL" [server's PID] ");
		ft_printf(LPCH"| \"message\"\n");
	}
	exit (1);
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_message(2);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_message(2);
		}
		i--;
		usleep(100);
	}
}

static void	handler(int sig)
{
	static int	bool = 1;

	if (sig == SIGUSR1 && bool)
	{
		ft_printf(LGTP"\nMessage received and printed with succes :)\n");
		bool = 0;
	}
	if (sig == SIGUSR2)
	{
		ft_printf(LGTV"\nSending message to server ...\n");
		bool = 1;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;
	int					i;

	if (ac != 3)
	{
		error_message(2);
		exit (1);
	}
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	return (0);
}
