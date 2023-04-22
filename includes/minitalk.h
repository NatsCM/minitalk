/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:13:23 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/22 22:26:16 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../minilibft/minilibft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_utils
{
	pid_t	pid_cl;
	int		cmptr;
	char	c;
	char	*msg;
}	t_utils;

// typedef struct s_vars
// {
// 	int		cmptr;
// 	char	c;
// }	t_vars;

/*----------------- ANSI Color codes -------------------*/
# define BBBL "\e[38;5;123m"
# define LGTV "\e[38;5;183m"
# define LGTP "\e[38;5;212m"
# define LPCH "\e[38;5;210m"
# define YLLW "\e[38;5;222m"

#endif