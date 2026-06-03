/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:13:48 by framirez          #+#    #+#             */
/*   Updated: 2026/05/31 16:03:29 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_node **stack)
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
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	rrb(t_data *data)
{
	if (reverse_rotate(&data->stack_b) == 1)
	{
		write(1, "rrb\n", 4);
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
	write(1, "rrr\n", 4);
	return (1);
}
