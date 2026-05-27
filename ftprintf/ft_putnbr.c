/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:47:38 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/08 19:17:11 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				bytes;
	int				temp;

	bytes = 0;
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		bytes++;
		nb = (unsigned int) -n;
	}
	else
		nb = (unsigned int) n;
	if (nb >= 10)
	{
		temp = ft_putunbr(nb / 10);
		if (temp < 0)
			return (-1);
		bytes += temp;
	}
	if (ft_putchar((nb % 10) + '0') < 0)
		return (-1);
	bytes++;
	return (bytes);
}
