/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:59:08 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 15:15:57 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_write_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_write_char('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_write_char(nb % 10 + 48);
}

int	ft_atoi(char *s)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (s[i] <= 32)
		++i;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
		nb = nb * 10 + (s[i++] - 48);
	return (nb * neg);
}
