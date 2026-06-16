/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:55:21 by framirez          #+#    #+#             */
/*   Updated: 2026/06/16 18:03:09 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->number;
	b = data->stack_a->next->number;
	c = data->stack_a->next->next->number;
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && a > c && c > b)
		ra(data);
	else if (a < b && a > c)
		rra(data);
	else if (a > b && a < c && b < c)
		sa(data);
	else
	{
		sa(data);
		ra(data);
	}
}

int	ft_sqrt(int num)
{
	int	i;

	i = 1;
	while (i * i <= num)
		i++;
	return (i);
}
