/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:34:47 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/17 12:09:28 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putfloat(double number)
{
	int	result;
	int	bytes;

	bytes = 0;
	if (number == 1)
		return (write (2, "100.00", 6));
	else if (number == 0)
		return (write (2, "0.00", 4));
	else
	{
		result = number * 10000;
		bytes += ft_putunbr(result / 100);
		bytes += ft_putchar('.');
		bytes += ft_putunbr(result % 100);
	}
	return (bytes);
}
