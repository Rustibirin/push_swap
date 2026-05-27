/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:58:46 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/01 19:15:02 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *) src;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *) &ptr[i]);
		i++;
	}
	return (0);
}
