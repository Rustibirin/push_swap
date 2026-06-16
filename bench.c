/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 12:58:33 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_total_ops(t_data *data)
{
	data->total_ops = data->sa_cnt + data->sb_cnt + data->ss_cnt
		+ data->pa_cnt + data->pb_cnt + data->ra_cnt + data->rb_cnt
		+ data->rr_cnt + data->rra_cnt + data->rrb_cnt + data->rr_cnt;
}

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

static void	ft_print_data(t_data *data)
{
	char	*strategy_arr[6];

	strategy_arr[0] = "SIMPLE / O(n2)";
	strategy_arr[1] = "MEDIUM / O(n√n)";
	strategy_arr[2] = "COMPLEX / O(n log n)";
	strategy_arr[3] = "ADAPTIVE / O(n2)";
	strategy_arr[4] = "ADAPTIVE / O(n√n)";
	strategy_arr[5] = "ADAPTIVE / O(n log n)";
	ft_total_ops(data);
	ft_printf("[bench] disorder: %f%%\n", data->dis_index);
	ft_printf("[bench] strategy: %s\n", strategy_arr[data->strategy]);
	ft_printf("[bench] total_ops: %i\n", data->total_ops);
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", data->sa_cnt,
		data->sb_cnt, data->ss_cnt, data->pa_cnt, data->pb_cnt);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
		data->ra_cnt, data->rb_cnt, data->rr_cnt, data->rra_cnt, data->rrb_cnt,
		data->rrr_cnt);
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
