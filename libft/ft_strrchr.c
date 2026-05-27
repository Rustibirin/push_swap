/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:16:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/01 23:26:39 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;
	char	ch;

	temp = NULL;
	ch = (char) c;
	while (*str)
	{
		if (*str == ch)
			temp = (char *) str;
		str++;
	}
	if (ch == '\0')
		return ((char *) str);
	return (temp);
}
