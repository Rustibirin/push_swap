/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:07:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 18:06:45 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_find_min_pos(t_node *stack)
{
	t_node	*act_node;
	int		min_value;
	int		min_pos;
	int		act_pos;

	act_node = stack->next;
	min_value = stack->number;
	min_pos = 0;
	act_pos = 1;
	while (act_node != stack)
	{
		if (act_node->number < min_value)
		{
			min_value = act_node->number;
			min_pos = act_pos;
		}
		act_node = act_node->next;
		act_pos++;
	}
	return (min_pos);
}

int	ft_simple(t_data *data)
{
	int	min_pos;

	if (data->size_a == 2)
		return (sa(data), 0);
	if (data->size_a == 3)
		return (ft_sort_three(data), 0);
	while (data->size_a > 3)
	{
		min_pos = ft_find_min_pos(data->stack_a);
		if (min_pos <= (data->size_a / 2))
		{
			while (min_pos--)
				ra(data);
		}
		else
		{
			while (min_pos++ < data->size_a)
				rra(data);
		}
		pb(data);
	}
	ft_sort_three(data);
	while (data->size_b > 0)
		pa(data);
	return (0);
}
