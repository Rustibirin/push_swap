/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:57 by framirez          #+#    #+#             */
/*   Updated: 2026/06/16 12:45:33 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_min_node(t_node *stack)
{
	t_node	*act_node;
	t_node	*min_node;

	act_node = stack;
	while (act_node->index != 0)
		act_node = act_node->next;
	min_node = act_node;
	act_node = act_node->next;
	while (act_node != stack)
	{
		if (act_node->number < min_node->number && act_node->index == 0)
			min_node = act_node;
		act_node = act_node->next;
	}
	return (min_node);
}

static void	index_assignment(t_data *data)
{
	int		count;
	t_node	*act_node;

	count = 1;
	while (count <= data->size_a)
	{
		act_node = ft_find_min_node(data->stack_a);
		act_node->index = count;
		count++;
	}
	return ;
}

static int	ft_find_max_pos(t_node *stack)
{
	int		max_pos;
	int		act_pos;
	t_node	*max_node;
	t_node	*act_node;

	max_node = stack;
	act_node = stack->next;
	max_pos = 0;
	act_pos = 1;
	while (act_node != stack)
	{
		if (act_node->number > max_node->number)
		{
			max_node = act_node;
			max_pos = act_pos;
		}
		act_pos++;
		act_node = act_node->next;
	}
	return (max_pos);
}

static void	chunks_to_b(t_data *data)
{
	int	chunk_size;
	int	index_limit;

	index_assignment(data);
	chunk_size = (double)ft_sqrt(data->size_a) * 1.4;
	index_limit = chunk_size;
	while (data->stack_a != NULL)
	{
		if (data->stack_a->index <= index_limit)
		{
			pb(data);
			if (data->stack_b->index <= index_limit / 2)
				rb(data);
		}
		else
			ra(data);
		if (data->size_b >= index_limit)
			index_limit = index_limit + chunk_size;
	}
}

int	ft_medium(t_data *data)
{
	int	max_pos;

	if (data->size_a == 2)
		return (sa(data), 0);
	if (data->size_a == 3)
		return (ft_sort_three(data), 0);
	chunks_to_b(data);
	while (data->stack_b != NULL)
	{
		max_pos = ft_find_max_pos(data->stack_b);
		if (max_pos > data->size_b / 2)
		{
			while (max_pos++ < data->size_b)
				rrb(data);
		}
		else
		{
			while (max_pos-- > 0)
				rb(data);
		}
		pa(data);
	}
	return (0);
}
