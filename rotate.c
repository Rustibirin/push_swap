/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:00:32 by framirez          #+#    #+#             */
/*   Updated: 2026/05/29 13:57:53 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	if (stack != NULL && *stack != NULL)
		*stack = (*stack)->next;
}

void	ra(t_data *data)
{
	rotate(&data->stack_a);
	write(1, "ra\n", 3);
}
void	rb(t_data *data)
{
	rotate(&data->stack_b);
	write(1, "rb\n", 3);
}
void	rr(t_data *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	write(1, "rr\n", 3);
}
