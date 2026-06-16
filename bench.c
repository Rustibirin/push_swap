/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 17:35:40 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_total_ops(t_data *data)
{
	data->total_ops = data->sa_cnt + data->sb_cnt + data->ss_cnt
		+ data->pa_cnt + data->pb_cnt + data->ra_cnt + data->rb_cnt
		+ data->rr_cnt + data->rra_cnt + data->rrb_cnt + data->rr_cnt;
}

void	ft_bench(t_data *data)
{
	const char	*strategy_arr[] = {"Adaptive", "Simple / O(n²)",
		"Medium / O(n√n)", "Complex / O(n log n)", "Adaptive / O(n²)",
		"Adaptive / O(n√n)", "Adaptive / O(n log n)"};

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
