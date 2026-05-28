/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:13:48 by framirez          #+#    #+#             */
/*   Updated: 2026/05/28 18:06:24 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack, int size)
{
	if (size > 0)
		*stack = (*stack)->prev;
}
void	rra(t_data *data)
{
	reverse_rotate(&data->stack_a, data->size_a);
}
void	rrb(t_data *data)
{
	reverse_rotate(&data->stack_b, data->size_b);
}
void	rrr(t_data *data)
{
	reverse_rotate(&data->stack_a, data->size_a);
	reverse_rotate(&data->stack_b, data->size_b);
}