/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:13:48 by framirez          #+#    #+#             */
/*   Updated: 2026/05/29 18:03:05 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	if (stack != NULL && *stack != NULL)
		*stack = (*stack)->prev;
}
void	rra(t_data *data)
{
	reverse_rotate(&data->stack_a);
	write(1, "rra\n", 4);
}
void	rrb(t_data *data)
{
	reverse_rotate(&data->stack_b);
	write(1, "rrb\n", 4);
}
void	rrr(t_data *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	write(1, "rrr\n", 4);
}