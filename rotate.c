/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:00:32 by framirez          #+#    #+#             */
/*   Updated: 2026/06/18 13:32:51 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	rotate(t_node **stack)
{
	if (stack != NULL && *stack != NULL)
	{
		*stack = (*stack)->next;
		return (1);
	}
	return (0);
}

int	ra(t_data *data)
{
	if (rotate(&data->stack_a) == 1)
	{
		if (data->flag_total_opers == 0)
			write(1, "ra\n", 3);
		data->ra_cnt++;
		return (1);
	}
	return (0);
}

int	rb(t_data *data)
{
	if (rotate(&data->stack_b) == 1)
	{
		if (data->flag_total_opers == 0)
			write(1, "rb\n", 3);
		data->rb_cnt++;
		return (1);
	}
	return (0);
}

int	rr(t_data *data)
{
	int	a;
	int	b;

	a = rotate(&data->stack_a);
	b = rotate(&data->stack_b);
	if (a == 0 && b == 0)
		return (0);
	if (data->flag_total_opers == 0)
		write(1, "rr\n", 3);
	data->rr_cnt++;
	return (1);
}
