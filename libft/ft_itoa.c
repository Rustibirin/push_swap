/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:36:01 by rumartin          #+#    #+#             */
/*   Updated: 2026/04/27 18:35:36 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_numbers(int n, int sign)
{
	int	numbers;

	if (n == 0)
		return (1);
	numbers = 0;
	while (n)
	{
		n = n / 10;
		numbers++;
	}
	return (numbers + sign);
}

static	char	*fill_str(char *res, int n, int sign, int numbers)
{
	res[numbers] = '\0';
	while (numbers > sign)
	{
		res[--numbers] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		numbers;

	sign = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	numbers = ft_count_numbers(n, sign);
	res = ft_calloc ((numbers + 1), sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, n, sign, numbers);
	return (res);
}
