/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:06:36 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/16 15:27:18 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

/*------------------------ utils -----------------------*/
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *s);
/*----------------- server fonctions -------------------*/
void	print_pid(pid_t pid);
void	handler_sig(int sig, siginfo_t *info, void *var);
/*----------------- client fonctions -------------------*/
void	send_char(pid_t pid, char c);

#endif
