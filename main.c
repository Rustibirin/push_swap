/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/31 13:59:30 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algorithms(t_data *data)
{
	if(data->strategy == SIMPLE)
		if (ft_simple())
			return (1);
	else if(data->strategy == MEDIUM)
		if (ft_medium())
			return (1);
	else if(data->strategy == COMPLEX)
		if (ft_complex())
			return (1);
	else
		if (ft_adaptive())
			return (1);
	return (0);
}
int	ft_sorted(t_node *stack)
{
	t_node	*act_node;

	if (!stack)
		return (0);
	act_node = stack;
	while (act_node->next != stack)
	{
		if (act_node->number > act_node->next->number)
			return (1);
		act_node = act_node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (ft_args_checker(argv, data))
		return (write(2, "Error\n", 6), ft_free_stack(&data->stack_a),
			free(data), 1);
	if (ft_sorted)
		ft_algorithms(data);
	return (ft_free_stack(&data->stack_a), free(data), 0);
}
