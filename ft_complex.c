/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:24:32 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 18:01:18 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_get_middle(t_data *data, t_node *stack, int size)
{
	int	*arr;
	int	i;
	int	temp;
	int	middle;

	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		ft_free_and_exit(data);
	ft_fill_array(stack, arr, size);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
	}
	middle = arr[size / 2];
	free (arr);
	return (middle);
}

static	int	ft_quicksort_b(t_data *data, int size)
{
	t_complex_vars	c_vars;

	if (size <= 2)
		return (ft_sort_small_b(data, size), 0);
	c_vars.middle = ft_get_middle(data, data->stack_b, size);
	c_vars.rb_count = 0;
	c_vars.pa_count = 0;
	while (size)
	{
		if (data->stack_b->number >= c_vars.middle)
		{
			pa(data);
			c_vars.pa_count++;
		}
		else
		{
			rb(data);
			c_vars.rb_count++;
		}
		size--;
	}
	ft_rewind_b(data, c_vars.rb_count);
	ft_quicksort_a(data, c_vars.pa_count);
	ft_quicksort_b(data, c_vars.rb_count);
	return (0);
}

static	int	ft_quicksort_a(t_data *data, int size)
{
	t_complex_vars	c_vars;

	if (size <= 2)
		return (ft_sort_small_a(data, size), 0);
	c_vars.middle = ft_get_middle(data, data->stack_a, size);
	c_vars.ra_count = 0;
	c_vars.pb_count = 0;
	while (size)
	{
		if (data->stack_a->number < c_vars.middle)
		{
			pb(data);
			c_vars.pb_count++;
		}
		else
		{
			ra(data);
			c_vars.ra_count++;
		}
		size--;
	}
	ft_rewind_a(data, c_vars.ra_count);
	ft_quicksort_a(data, c_vars.ra_count);
	ft_quicksort_b(data, c_vars.pb_count);
	return (0);
}

int	ft_complex(t_data *data)
{
	if (data->size_a == 3)
		return (ft_sort_three(data), 0);
	ft_quicksort_a(data, data->size_a);
	return (0);
}
