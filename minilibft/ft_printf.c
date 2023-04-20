/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:36:49 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 15:16:26 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_formats(format[i], args);
		}
		else
			size += ft_writechar(format[i]);
	}
	va_end(args);
	return (size);
}
