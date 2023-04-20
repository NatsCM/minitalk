/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:44:09 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 15:16:10 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	ft_formats(char f, va_list args)
{
	int	size;

	size = 0;
	if (f == 'c')
		size += ft_writechar(va_arg(args, int));
	else if (f == 'd' || f == 'i')
		size += ft_writenbr(va_arg(args, int));
	else if (f == 'u')
		size += ft_writenbr(va_arg(args, unsigned int));
	else if (f == 's')
		size += ft_writestr(va_arg(args, char *));
	else if (f == 'p')
	{
		size += ft_writestr("0x");
		size += ft_put_p(va_arg(args, unsigned long), 0);
	}
	else if (f == 'x')
		size += ft_puthexa(va_arg(args, unsigned int), 0);
	else if (f == 'X')
		size += ft_puthexa(va_arg(args, unsigned int), 32);
	else if (f == '%')
		size += ft_writechar('%');
	return (size);
}
