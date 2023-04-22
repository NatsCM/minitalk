/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:27:00 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/22 22:42:11 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_utils	g_utils;

static void	error_m(int error)
{
	if (error == 1)
	{
		ft_printf(LPCH"\nWrong format. Please try: ");
		ft_printf(BBBL"./server\n");
	}
	else if (error == 2)
		ft_printf(LPCH"\nCould not send signal to client\n");
}

static void	send_sig_to_cl(int sig)
{
	if (kill(g_utils.pid_cl, sig) == -1)
	{
		error_m(2);
	}
}

static void	add_char_to_msg(char c)
{
	char	*new_msg;
	size_t	old_size;

	old_size = 0;
	if (g_utils.msg != NULL)
		old_size = ft_strlen(g_utils.msg);
	new_msg = malloc(old_size + 2);
	if (new_msg)
	{
		if (g_utils.msg != NULL)
			ft_memcpy(new_msg, g_utils.msg, old_size);
		new_msg[old_size] = c;
		new_msg[old_size + 1] = '\0';
		free(g_utils.msg);
		g_utils.msg = new_msg;
	}
}

static void	handler_sig(int sig, siginfo_t *info_cl, void *var)
{
	static t_utils	hdl;

	(void)var;
	if (info_cl->si_pid)
		g_utils.pid_cl = info_cl->si_pid;
	hdl.c |= (sig == SIGUSR1);
	if (++hdl.cmptr == 8)
	{
		if (hdl.c == '\0')
		{
			send_sig_to_cl(SIGUSR1);
			if (g_utils.msg)
			{
				ft_printf(BBBL"%s\n", g_utils.msg);
				free(g_utils.msg);
				g_utils.msg = NULL;
			}
		}
		else
			add_char_to_msg(hdl.c);
		hdl.cmptr = 0;
		hdl.c = 0;
	}
	else
		hdl.c <<= 1;
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
	ft_printf(LGTV"PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
