/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:13:23 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/23 06:33:41 by ncardozo         ###   ########.fr       */
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
	pid_t	pid;
	int		cmptr;
	int		i;
	size_t	old_size;
	char	c;
	char	*new_msg;
	char	*msg;
}	t_utils;

/*----------------- ANSI Color codes -------------------*/
# define BB "\e[38;5;123m"
# define LV "\e[38;5;183m"
# define LP "\e[38;5;225m"
# define PCH "\e[38;5;210m"
# define LY "\e[38;5;222m"

#endif