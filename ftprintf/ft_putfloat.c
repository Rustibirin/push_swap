/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:34:47 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:03 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putfloat(float number)
{
	int	result;
	int	bytes;

	if (number == 1)
		write (2, "1", 1);
	else if (number == 0)
		write (2, "0", 1);
	else
	{
		result = (int) number * 10000;
		bytes += ft_putchar(result / 100);
		bytes += ft_putchar('.');
		bytes += ft_putchar(result % 100);
	}
	return(bytes);
}

int	main(void)
{
	float	number;
	int 	result;

	number = 0.4573;
	result = ft_putfloat(number);
	printf("%i\n", result);
	return (0);
}