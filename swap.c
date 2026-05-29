/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:37:35 by framirez          #+#    #+#             */
/*   Updated: 2026/05/29 18:00:56 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*a;
	t_node	*b;

	if (stack == NULL || *stack == NULL || (*stack)->next == *stack)
		return ;
	a = *stack;
	b = a->next;
	if (b->next == a)
		*stack = b;
	else
	{
		b->next->prev = a; // conectar C - A
		a->prev->next = b; // conectar D - B
		a->next = b->next; // conectar A - C
		b->prev = a->prev; // conectar B - D
		b->next = a;       // conectar B - A
		a->prev = b;       // conectar A - B
		*stack = b;
	}
}
void	sa(t_data *data)
{
	swap(&data->stack_a);
	write(1, "sa\n", 3);
}
void	sb(t_data *data)
{
	swap(&data->stack_b);
	write(1, "sb\n", 3);
}
void	ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	write(1, "ss\n", 3);
}
