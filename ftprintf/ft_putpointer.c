/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:46:37 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:05 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	uintptr_t	mem;
	int			bytes;

	if (!ptr)
		return (write(2, "(nil)", 5));
	bytes = write(2, "0x", 2);
	if (bytes < 0)
		return (-1);
	mem = (uintptr_t) ptr;
	bytes += ft_puthex('x', mem);
	return (bytes);
}
