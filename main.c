/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/17 13:03:39 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_adaptive(t_data *data)
{
	if (data->dis_index < 0.2)
	{
		ft_simple(data);
		data->strategy = ADAPTIVE_SIMPLE;
	}
	else if (data->dis_index >= 0.2 && data->dis_index < 0.5)
	{
		ft_medium(data);
		data->strategy = ADAPTIVE_MEDIUM;
	}
	else if (data->dis_index >= 0.5)
	{
		ft_complex(data);
		data->strategy = ADAPTIVE_COMPLEX;
	}
}

static	void	ft_algorithms(t_data *data)
{
	if (data->strategy == SIMPLE)
		ft_simple(data);
	else if (data->strategy == MEDIUM)
		ft_medium(data);
	else if (data->strategy == COMPLEX)
		ft_complex(data);
	else
		ft_adaptive(data);
}

static	double	ft_compute_disorder(t_node *stack)
{
	t_node	*node_i;
	t_node	*node_j;
	long	mistakes;
	long	total_pairs;

	if (!stack || stack->next == stack)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	node_i = stack;
	while (node_i->next != stack)
	{
		node_j = node_i->next;
		while (node_j != stack)
		{
			total_pairs++;
			if (node_i->number > node_j->number)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return ((double) mistakes / total_pairs);
}

static	int	ft_sorted(t_node *stack)
{
	t_node	*act_node;

	if (!stack)
		return (1);
	act_node = stack;
	while (act_node->next != stack)
	{
		if (act_node->number > act_node->next->number)
			return (0);
		act_node = act_node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_args_checker(argv, data);
	if (!ft_sorted(data->stack_a))
	{
		data->dis_index = ft_compute_disorder(data->stack_a);
		ft_algorithms(data);
	}
	if (data->size_a)
		if (data->bench)
			ft_bench(data);
	return (ft_free_stack(&data->stack_a), ft_free_stack(&data->stack_b),
		free(data), 0);
}
