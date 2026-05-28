/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:37:35 by framirez          #+#    #+#             */
/*   Updated: 2026/05/28 18:06:29 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack, int size)
{
	t_node	*a;
	t_node	*b;

	a = *stack;
	b = a->next;
	if (size < 2)
		return ;
	else if (size == 2)
	{
		*stack = b;
	}
	else
	{
		b->next->prev = a; // conectar C - A
		a->prev->next = b; // conectar D - B
		a->next = b->next; // conectar A - C
		b->prev = a->prev; // conectar B - D
		b->next = a;       // conectar B - A
		a->prev = b;       // conectar A - B
		stack = b;
	}
}
void	sa(t_data *data)
{
	swap(&data->stack_a, data->size_a);
}
void	sb(t_data *data)
{
	swap(&data->stack_b, data->size_b);
}
void	ss(t_data *data)
{
	swap(&data->stack_a, data->size_a);
	swap(&data->stack_b, data->size_b);
}
