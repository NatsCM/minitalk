/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:44:36 by ncardozo          #+#    #+#             */
/*   Updated: 2023/04/18 13:55:36 by ncardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_writenbr(long int nb);
int		ft_puthexa(unsigned int nb, int maj);
int		ft_writestr(char *str);
int		ft_writechar(char c);
int		ft_printf(const char *format, ...);
int		ft_formats(char f, va_list args);
int		ft_put_p(unsigned long nb, int maj);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *s);

#endif
