/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:24:32 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/02 21:17:23 by rumartin         ###   ########.fr       */
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

int	ft_get_middle(t_node *stack, int size)
{
	int	*arr;
	int	i;
	int	temp;
	int	middle;

	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		return (1); // No puede ser 1. Tengo qué pensar cómo resolver este return de fallo.
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
int	ft_complex(t_data *data)
{
	int	middle;

	middle = ft_get_middle(data->stack_a, data->size_a);
	return (0);
}