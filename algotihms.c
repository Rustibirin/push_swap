/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotihms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:07:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/01 18:55:01 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_find_min_pos(t_node *stack)
{
	t_node	*act_node;
	int		min_value;
	int		min_pos;
	int		act_pos;

	act_node = stack->next;
	min_value = stack->number;
	min_pos = 0;
	act_pos = 1;
	while (act_node != stack)
	{
		if (act_node->number < min_value)
		{
			min_value = act_node->number;
			min_pos = act_pos;
		}
		act_node = act_node->next;
		act_pos++;
	}
	return (min_pos);
}

static	void	ft_sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->number;
	b = data->stack_a->next->number;
	c = data->stack_a->prev->number;
	if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && a > c && c > b)
		ra(data);
	else if (a < b && a > c)
		rra(data);
	else if (a > b && a < c && b < c)
		sa(data);
	else
	{
		sa(data);
		ra(data);
	}
}

int	ft_simple(t_data *data)
{
	int	min_pos;

	if (data->size_a == 2)
		return (sa(data), 0);
	if (data->size_a == 2)
		return (ft_sort_three(data), 0);
	while (data->size_a > 3)
	{
		min_pos = ft_find_min_pos(data->stack_a);
		if (min_pos <= (data->size_a / 2))
		{
			while (min_pos--)
				ra(data);
		}
		else
		{
			while (min_pos++ < data->size_a)
				rra(data);
		}
		pb(data);
	}
	ft_sort_three(data);
	while (data->size_b > 0)
		pa(data);
	return (0);
}

int	ft_medium(t_data *data)
{
	data->size_b = 2; //borrar
	return (0);
}

int	ft_complex(t_data *data)
{
	data->size_b = 3; //borrar
	return (0);
}

int	ft_adaptive(t_data *data)
{
	data->size_b = 4; //borrar
	return (0);
}
