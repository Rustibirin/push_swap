/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:01:27 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 17:05:34 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (*str)
	{
		res++;
		str++;
	}
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (n)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}

static	size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
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

static	char	*ft_strdup(const char *str)
{
	char	*cp;
	size_t	len;

	len = ft_strlen(str);
	cp = ft_calloc ((len + 1), sizeof(char));
	if (!cp)
		return (NULL);
	ft_strlcpy(cp, str, len + 1);
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_s = ft_calloc ((len + 1), sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
