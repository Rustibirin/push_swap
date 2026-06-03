/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:28:52 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/03 10:05:46 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rewind_a(t_data *data, int ra_count)
{
	while (ra_count--)
		rra(data);
	return (0);
}

int	ft_rewind_b(t_data *data, int rb_count)
{
	while (rb_count--)
		rrb(data);
	return (0);
}

int	ft_sort_small_a(t_data *data, int size)
{
	if (size == 2)
		if (data->stack_a->number > data->stack_a->next->number)
			sa(data);
	return (0);
}

int	ft_sort_small_b(t_data *data, int size)
{
	if (size == 0)
		return (0);
	if (size == 1)
		pa(data);
	if (size == 2)
		if (data->stack_b->number < data->stack_b->next->number)
			sb(data);
		pa(data);
		pa(data);
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