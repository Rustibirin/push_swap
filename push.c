/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:03:47 by framirez          #+#    #+#             */
/*   Updated: 2026/06/02 23:39:51 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*extract_node(t_node **stack_src)
{
	t_node	*node;

	node = *stack_src;
	if ((*stack_src)->next == *stack_src)
		*stack_src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*stack_src = node->next;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	push(t_node **stack_src, t_node **stack_dest)
{
	t_node	*node;
	t_node	*last_dest;

	if (stack_src == NULL || *stack_src == NULL)
		return (0);
	node = extract_node(stack_src);
	if (*stack_dest == NULL)
	{
		*stack_dest = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last_dest = (*stack_dest)->prev;
		node->next = (*stack_dest);
		(*stack_dest)->prev = node;
		last_dest->next = node;
		node->prev = last_dest;
		*stack_dest = node;
	}
	return (1);
}

int	pa(t_data *data)
{
	if (push(&data->stack_b, &data->stack_a) == 1)
	{
		data->size_a++;
		data->size_b--;
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	pb(t_data *data)
{
	if (push(&data->stack_a, &data->stack_b) == 1)
	{
		data->size_a--;
		data->size_b++;
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}
