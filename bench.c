/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/01 18:36:32 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static	void	ft_print_stack(t_node *stack)
{
	t_node	*first_node;
	t_node	*act_node;
	int		i;

	if (!stack)
	{
		printf("El stack requerido esta vacio\n");
		return ;
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

static	void	ft_print_data(t_data *data)
{
	char	*strategy_arr[4];
	char	*bench_arr[2];

	strategy_arr[0] = "SIMPLE";
	strategy_arr[1] = "MEDIUM";
	strategy_arr[2] = "COMPLEX";
	strategy_arr[3] = "ADAPTIVE";
	bench_arr[0] = "NO";
	bench_arr[1] = "YES";
	printf("La estrategia elegida es: %s\n", strategy_arr[data->strategy]);
	printf("[bench] Bench: %s\n", bench_arr[data->bench]);
	printf("[bench] El puntero a el stack A es: %p\n", data->stack_a);
	printf("[bench] El numero de nodos en el stack A es: %i\n", data->size_a);
	printf("[bench] El puntero al stack B es: %p\n", data->stack_b);
	printf("[bench] El numero de nodos en el stack B es: %i\n", data->size_b);
	printf("[bench] El indice de desorden es: %f\n", data->dis_index);
}

void	ft_bench(t_data *data)
{
	printf("\n---------------------- DATA ----------------------\n");
	ft_print_data(data);
	printf("\n---------------------- STACK A ----------------------\n");
	ft_print_stack(data->stack_a);
	printf("\n---------------------- STACK B ----------------------\n");
	ft_print_stack(data->stack_b);
}
