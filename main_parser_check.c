/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 13:10:43 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main_parser_checker(int argc, char **argv)
{
	t_data	*data;
	t_node	*first_node;
	t_node	*act_node;
	int		i;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (ft_args_checker(argv, data))
		return (write(2, "Error\n", 6), ft_free_stack(&data->stack_a),
			free(data), 1);
	printf("La estrategia elegida es: %i\n", data->strategy);
	printf("Bench = %i\n", data->bench);
	printf("El puntero a el stack A es: %p\n", data->stack_a);
	printf("El numero de nodos en el stack A es: %i\n", data->size_a);
	printf("El puntero al stack B es: %p\n", data->stack_b);
	printf("El numero de nodos en el stack B es: %i\n", data->size_b);
	first_node = data->stack_a;
	act_node = first_node->next;
	i = 1;
	printf("El valor del nodo %i es: %i\n", i++, first_node->number);
	while (act_node != first_node)
	{
		printf("El valor del nodo %i es: %i\n", i, act_node->number);
		i++;
		act_node = act_node->next;
	}
	return (ft_free_stack(&data->stack_a), free(data), 0);
}
