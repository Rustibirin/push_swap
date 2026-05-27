/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:20:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/01 18:43:13 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dest_size == 0)
		return (src_len);
	if (src_len < dest_size)
		ft_memcpy(dest, src, src_len + 1);
	else
	{
		ft_memcpy(dest, src, dest_size - 1);
		dest[dest_size - 1] = '\0';
	}
	return (src_len);
}
