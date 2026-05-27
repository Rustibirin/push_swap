/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:46:37 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/08 19:43:11 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	uintptr_t	mem;
	int			bytes;

	if (!ptr)
		return (write(1, "(nil)", 5));
	bytes = write(1, "0x", 2);
	if (bytes < 0)
		return (-1);
	mem = (uintptr_t) ptr;
	bytes += ft_puthex('x', mem);
	return (bytes);
}
