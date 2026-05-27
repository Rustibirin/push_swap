/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:45 by rumartin          #+#    #+#             */
/*   Updated: 2026/04/27 18:36:15 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s12 = ft_calloc ((len_s1 + len_s2 + 1), sizeof(char));
	if (!s12)
		return (NULL);
	ft_strlcpy(s12, s1, len_s1 + 1);
	ft_strlcpy(s12 + len_s1, s2, len_s2 + 1);
	return (s12);
}
