/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:13:48 by framirez          #+#    #+#             */
/*   Updated: 2026/06/18 13:33:02 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	reverse_rotate(t_node **stack)
{
	if (stack != NULL && *stack != NULL && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
		return (1);
	}
	return (0);
}

int	rra(t_data *data)
{
	if (reverse_rotate(&data->stack_a) == 1)
	{
		if (data->flag_total_opers == 0)
			write(1, "rra\n", 4);
		data->rra_cnt++;
		return (1);
	}
	return (0);
}

int	rrb(t_data *data)
{
	if (reverse_rotate(&data->stack_b) == 1)
	{
		if (data->flag_total_opers == 0)
			write(1, "rrb\n", 4);
		data->rrb_cnt++;
		return (1);
	}
	return (0);
}

int	rrr(t_data *data)
{
	int	a;
	int	b;

	a = reverse_rotate(&data->stack_a);
	b = reverse_rotate(&data->stack_b);
	if (a == 0 && b == 0)
		return (0);
	if (data->flag_total_opers == 0)
		write(1, "rrr\n", 4);
	data->rrr_cnt++;
	return (1);
}
