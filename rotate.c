/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:00:32 by framirez          #+#    #+#             */
/*   Updated: 2026/06/13 13:24:57 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
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
		write(1, "ra\n", 3);
		data->op_count++;
		return (1);
	}
	return (0);
}

int	rb(t_data *data)
{
	if (rotate(&data->stack_b) == 1)
	{
		write(1, "rb\n", 3);
		data->op_count++;
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
	write(1, "rr\n", 3);
	data->op_count++;
	return (1);
}
