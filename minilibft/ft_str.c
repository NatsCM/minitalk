/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:44:58 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 15:16:36 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	ft_writechar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_writestr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i = ft_writestr("(null)");
	else
	{
		while (str[i])
		{
			ft_writechar(str[i]);
			i++;
		}
	}
	return (i);
}
