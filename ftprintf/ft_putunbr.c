/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:49:13 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:07 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	bytes;
	int	temp;

	bytes = 0;
	if (n >= 10)
	{
		temp = ft_putunbr(n / 10);
		if (temp < 0)
			return (-1);
		bytes += temp;
	}
	if (ft_putchar((n % 10) + '0') < 0)
		return (-1);
	bytes++;
	return (bytes);
}
