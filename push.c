/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:03:47 by framirez          #+#    #+#             */
/*   Updated: 2026/05/29 18:04:51 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_src, t_node **stack_dest)
{
	t_node	*node;

	if (stack_src == NULL || *stack_src == NULL)
		return ;
	node = *stack_src;
	if ((*stack_src)->next == *stack_src)
		*stack_src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack_src = node->next;
	}
	if (*stack_dest == NULL)
	{
		*stack_dest = node;
		(*stack_dest)->next = *stack_dest;
		(*stack_dest)->prev = *stack_dest;
	}
	else
	{
		(*stack_dest)->prev = node;
		node->next = *stack_dest;
		node->prev = (*stack_dest)->prev->prev;
		*stack_dest = node;
	}
}
void	pa(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	write(1, "pa\n", 3);
}
void	pb(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	write(1, "pb\n", 3);
}
