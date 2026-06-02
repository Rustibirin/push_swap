/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:24:32 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/02 23:12:13 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_fill_array(t_node *stack, int *arr, int size)
{
	t_node	*act_node;
	int		i;

	if (!stack)
		return ;
	act_node = stack;
	i = 0;
	while (i < size)
	{
		arr[i] = act_node->number;
		act_node = act_node->next;
		i++;
	}
}

int	ft_get_middle(t_data *data)
{
	int	*arr;
	int	i;
	int	temp;
	int	middle;

	arr = ft_calloc(data->size_a, sizeof(int));
	if (!arr)
		ft_free_and_exit(data);
	ft_fill_array(data->stack_a, arr, data->size_a);
	i = 0;
	while (i < data->size_a - 1)
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
	middle = arr[data->size_a / 2];
	free (arr);
	return (middle);
}
int	ft_complex(t_data *data)
{
	int	middle;

	middle = ft_get_middle(data);
	(void) middle;
	return (0);
}