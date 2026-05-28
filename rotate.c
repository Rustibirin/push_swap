/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:00:32 by framirez          #+#    #+#             */
/*   Updated: 2026/05/28 18:06:40 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack, int size)
{
	if (*stack != NULL && stack != NULL)
		*stack = (*stack)->next;
}

void	ra(t_data *data)
{
	rotate(&data->stack_a, data->size_a);
}
void	rb(t_data *data)
{
	rotate(&data->stack_b, data->size_b);
}
void	rr(t_data *data)
{
	rotate(&data->stack_a, data->size_a);
	rotate(&data->stack_b, data->size_b);
}
