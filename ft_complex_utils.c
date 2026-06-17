/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:28:52 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/17 20:19:29 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rewind_a(t_data *data, int ra_times)
{
	if (ra_times > (data->size_a / 2))
	{
		while (ra_times != data->size_a)
		{
			ra(data);
			ra_times++;
		}
	}
	else
	{
		while (ra_times)
		{
			rra(data);
			ra_times--;
		}
	}
	return (0);
}

int	ft_rewind_b(t_data *data, int rb_times)
{
	if (rb_times > (data->size_b / 2))
	{
		while (rb_times != data->size_b)
		{
			rb(data);
			rb_times++;
		}
	}
	else
	{
		while (rb_times)
		{
			rrb(data);
			rb_times--;
		}
	}
	return (0);
}

int	ft_sort_break_a(t_data *data, int size)
{
	if (size == 2)
		if (data->stack_a->number > data->stack_a->next->number)
			sa(data);
	return (0);
}

int	ft_sort_break_b(t_data *data, int size)
{
	if (size == 0)
		return (0);
	if (size == 1)
		pa(data);
	if (size == 2)
	{
		if (data->stack_b->number < data->stack_b->next->number)
			sb(data);
		pa(data);
		pa(data);
	}
	return (0);
}

void	ft_fill_array(t_node *stack, int *arr, int size)
{
	t_node	*act_node;
	int		i;

	if (!stack)
		return ;
	act_node = stack;
	i = 0;
	while (i < size)
	{
		arr[i] = act_node->number;
		act_node = act_node->next;
		i++;
	}
}
