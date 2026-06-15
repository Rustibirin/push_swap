/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 17:33:02 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_node *stack)
{
	t_node	*first_node;
	t_node	*act_node;
	int		i;

	if (!stack)
	{
		ft_printf("El stack requerido esta vacio\n");
		return ;
	}
	first_node = stack;
	act_node = first_node->next;
	ft_printf("\n---------------------- %p ----------------------\n", stack);
	i = 1;
	ft_printf("El valor del nodo %i es: %i\n", i++, first_node->number);
	while (act_node != first_node)
	{
		ft_printf("El valor del nodo %i es: %i\n", i, act_node->number);
		i++;
		act_node = act_node->next;
	}
}
#include <stdio.h>

static void	ft_print_data(t_data *data)
{
	char	*strategy_arr[4];
	char	*bench_arr[2];

	data->dis_index = data->dis_index * 100;
	strategy_arr[0] = "SIMPLE / O(n2)";
	strategy_arr[1] = "MEDIUM / O(nRaizn)";
	strategy_arr[2] = "COMPLEX / O(n log n)";
	strategy_arr[3] = "ADAPTIVE";
	bench_arr[0] = "NO";
	bench_arr[1] = "YES";
	ft_printf("La estrategia elegida es: %s\n", strategy_arr[data->strategy]);
	ft_printf("Bench: %s\n", bench_arr[data->bench]);
	ft_printf("El puntero a el stack A es: %p\n", data->stack_a);
	ft_printf("El numero de nodos en el stack A es: %i\n", data->size_a);
	ft_printf("El puntero al stack B es: %p\n", data->stack_b);
	ft_printf("El numero de nodos en el stack B es: %i\n", data->size_b);
	ft_printf("El indice de desorden es: %f%%\n", (int)data->dis_index);
}

void	ft_bench(t_data *data)
{
	ft_printf("\n---------------------- DATA ----------------------\n");
	ft_print_data(data);
	ft_printf("\n---------------------- STACK A ----------------------\n");
	ft_print_stack(data->stack_a);
	ft_printf("\n---------------------- STACK B ----------------------\n");
	ft_print_stack(data->stack_b);
}
