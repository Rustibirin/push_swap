/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:08:54 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:00 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_error(va_list arguments)
{
	va_end(arguments);
	return (-1);
}

static	int	ft_secretary(const char *format, va_list arguments)
{
	int	bytes;

	bytes = 0;
	if (*format == '%')
		bytes = ft_putchar('%');
	else if (*format == 'c')
		bytes = ft_putchar(va_arg(arguments, int));
	else if (*format == 's')
		bytes = ft_putstr(va_arg(arguments, char *));
	else if (*format == 'p')
		bytes = ft_putpointer(va_arg(arguments, void *));
	else if (*format == 'd' || *format == 'i')
		bytes = ft_putnbr(va_arg(arguments, int));
	else if (*format == 'u')
		bytes = ft_putunbr(va_arg(arguments, unsigned int));
	else if (*format == 'x' || *format == 'X')
		bytes = ft_puthex(*format, (uintptr_t) va_arg(arguments, unsigned int));
	else if (*format == 'f')
		bytes = ft_putfloat(va_arg(arguments, double));
	else
		bytes = write(2, format, 1);
	if (bytes < 0)
		return (-1);
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		res;
	int		temp;

	res = 0;
	va_start (arguments, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (ft_putchar(*format) < 0)
				return (ft_error(arguments));
			res++;
		}
		else if (*++format)
		{
			temp = ft_secretary(format, arguments);
			if (temp < 0)
				return (ft_error(arguments));
			res += temp;
		}
		++format;
	}
	va_end(arguments);
	return (res);
}
