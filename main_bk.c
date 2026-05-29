/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 16:15:35 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_node *stack)
{
	t_node	*first_node;
	t_node	*act_node;
	int		i;

	if (!stack)
	{
		printf("El stack requerido esta vacio\n");
		return;
	}
	first_node = stack;
	act_node = first_node->next;
	printf("\n---------------------- %p ----------------------\n", stack);
	i = 1;
	printf("El valor del nodo %i es: %i\n", i++, first_node->number);
	while (act_node != first_node)
	{
		printf("El valor del nodo %i es: %i\n", i, act_node->number);
		i++;
		act_node = act_node->next;
	}
}

void	ft_print_data(t_data *data)
{
	char *strategy_arr[] = {"SIMPLE", "MEDIUM", "COMPLEX", "ADAPTIVE"};
	char *bench_arr[] = {"NO", "YES"};
	
	printf("[bench] La estrategia elegida es: %s\n", strategy_arr[data->strategy]);
	printf("[bench] Bench: %s\n", bench_arr[data->bench]);
	printf("[bench] El puntero a el stack A es: %p\n", data->stack_a);
	printf("[bench] El numero de nodos en el stack A es: %i\n", data->size_a);
	printf("[bench] El puntero al stack B es: %p\n", data->stack_b);
	printf("[bench] El numero de nodos en el stack B es: %i\n", data->size_b);
}

void	ft_log(t_data *data)
{
	printf("\n---------------------- DATA ----------------------\n");
	ft_print_data(data);
	printf("\n---------------------- STACK A ----------------------\n");
	ft_print_stack(data->stack_a);
	printf("\n---------------------- STACK B ----------------------\n");
	ft_print_stack(data->stack_b);
	printf("\n---------------------- Movimientos ----------------------\n");
	rra(data);
	sa(data);
	ra(data);
	sa(data);
	printf("\n---------------------- STACK A ----------------------\n");
	ft_print_stack(data->stack_a);
	printf("\n---------------------- STACK B ----------------------\n");
	ft_print_stack(data->stack_b);
	printf("\n---------------------- DATA ----------------------\n");
	ft_print_data(data);
}

int	main_bk(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (ft_args_checker(argv, data))
		return (write(2, "Error\n", 6), ft_free_stack(&data->stack_a),
			ft_free_stack(&data->stack_b), free(data), 1);
	ft_log(data);
	return (ft_free_stack(&data->stack_a),
		ft_free_stack(&data->stack_b), free(data), 0);
}
