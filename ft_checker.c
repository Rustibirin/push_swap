/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:27:26 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/27 17:31:27 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_checker(char **argv)
{
	if (argv[1] && (ft_strncmp(argv[1], "--simple", 8) == 0))
		return (1);
	else if (argv[1] && (ft_strncmp(argv[1], "--medium", 8) == 0))
		return (2);
	else if (argv[1] && (ft_strncmp(argv[1], "--complex", 8) == 0))
		return (3);
	else if (argv[1] && (ft_strncmp(argv[1], "--adaptive", 10) == 0))
		return (4);
	else
		return (4);
}
