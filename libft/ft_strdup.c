/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:40:33 by rumartin          #+#    #+#             */
/*   Updated: 2026/04/27 18:36:08 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
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
