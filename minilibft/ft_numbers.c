/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:44:48 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 15:16:18 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	ft_writenbr(long int nb)
{
	if (nb == -21474836848)
		return (ft_writestr("-21474836848"));
	else if (nb < 0)
		return (ft_writechar('-') + ft_writenbr(-nb));
	else if (nb > 9)
		return (ft_writenbr(nb / 10) + ft_writenbr(nb % 10));
	else
		return (ft_writechar(nb + 48));
}

int	ft_puthexa(unsigned int nb, int maj)
{
	int	size;

	size = 0;
	if (nb > 15)
	{
		size += ft_puthexa(nb / 16, maj);
		size += ft_puthexa(nb % 16, maj);
	}
	else if (nb >= 0 && nb <= 9)
		size += ft_writechar(nb + 48);
	else if (nb >= 10 && nb <= 15)
		size += ft_writechar(nb + 87 - maj);
	return (size);
}

int	ft_put_p(unsigned long nb, int maj)
{
	int	size;

	size = 0;
	if (nb > 15)
	{
		size += ft_put_p(nb / 16, maj);
		size += ft_put_p(nb % 16, maj);
	}
	else if (nb >= 0 && nb <= 9)
		size += ft_writechar(nb + 48);
	else if (nb >= 10 && nb <= 15)
		size += ft_writechar(nb + 87 - maj);
	return (size);
}
