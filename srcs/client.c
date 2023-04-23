/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:30 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/23 06:32:53 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	error_message(int error)
{
	if (error == 1)
		ft_printf(PCH"\nWrong PID. Try again\n");
	else if (error == 2)
	{
		ft_printf(PCH"\nWrong format. please try: ./client |");
		ft_printf(BB" [server's PID] ");
		ft_printf(PCH"| \"message\"\n");
	}
	exit (1);
}

static void	send_char(pid_t pid, char c)
{
	t_utils	utils;

	utils.i = 7;
	while (utils.i >= 0)
	{
		if (c >> utils.i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_message(2);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_message(2);
		}
		utils.i--;
		usleep(100);
	}
}

static void	handler(int sig)
{
	static t_utils	utils;

	if (sig == SIGUSR1 && utils.i == 0)
	{
		ft_printf(LP"\nMessage received and printed with success!\n");
		utils.i = 1;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	t_utils				utils;

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
	utils.pid = ft_atoi(av[1]);
	utils.cmptr = 0;
	while (av[2][utils.cmptr])
	{
		send_char(utils.pid, av[2][utils.cmptr]);
		utils.cmptr++;
	}
	send_char(utils.pid, '\0');
	return (0);
}
