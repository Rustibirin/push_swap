/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:03:47 by framirez          #+#    #+#             */
/*   Updated: 2026/05/29 17:24:52 by framirez         ###   ########.fr       */
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
	push();
}
void	pb(t_data *data)
{
}
