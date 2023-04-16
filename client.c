/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:11:30 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/16 14:50:33 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t		pid;
	int			i;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (write(1, "Invalid number of arguments", 27));
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	return (0);
}
