/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:45:58 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:03 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int c, uintptr_t n)
{
	char	*dict;
	int		bytes;
	int		temp;

	if (c == 'x')
		dict = "0123456789abcdef";
	else
		dict = "0123456789ABCDEF";
	bytes = 0;
	if (n >= 16)
	{
		temp = ft_puthex(c, n / 16);
		if (temp < 0)
			return (-1);
		bytes += temp;
	}
	if (ft_putchar(dict[n % 16]) < 0)
		return (-1);
	bytes++;
	return (bytes);
}
