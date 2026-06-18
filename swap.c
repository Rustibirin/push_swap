/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:37:35 by framirez          #+#    #+#             */
/*   Updated: 2026/06/18 13:32:41 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	swap(t_node **stack)
{
	t_node	*a;
	t_node	*b;

	if (stack == NULL || *stack == NULL || (*stack)->next == *stack)
		return (0);
	a = *stack;
	b = a->next;
	if (b->next == a)
		*stack = b;
	else
	{
		b->next->prev = a;
		a->prev->next = b;
		a->next = b->next;
		b->prev = a->prev;
		b->next = a;
		a->prev = b;
		*stack = b;
	}
	return (1);
}

int	sa(t_data *data)
{
	if (swap(&data->stack_a) == 0)
	{
		if (data->flag_total_opers == 1)
			write(1, "sa\n", 3);
		data->sa_cnt++;
		return (1);
	}
	return (0);
}

int	sb(t_data *data)
{
	if (swap(&data->stack_b) == 0)
	{
		if (data->flag_total_opers == 1)
			write(1, "sb\n", 3);
		data->sb_cnt++;
		return (1);
	}
	return (0);
}

int	ss(t_data *data)
{
	int	a;
	int	b;

	a = swap(&data->stack_a);
	b = swap(&data->stack_b);
	if (a == 0 && b == 0)
		return (0);
	if (data->flag_total_opers == 0)
		write(1, "ss\n", 3);
	data->ss_cnt++;
	return (1);
}
