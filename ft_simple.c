/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:07:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 21:40:02 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_simple(t_data *data)
{
	if (data->size_a == 2)
		return (sa(data), 0);
	ft_sort_puppy(data);
	return (0);
}
