/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:20:22 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/17 12:37:38 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*act_node;
	t_node	*first_node;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;
	first_node = *stack;
	act_node = first_node->next;
	while (act_node != first_node)
	{
		next_node = act_node->next;
		free(act_node);
		act_node = next_node;
	}
	free(first_node);
	*stack = NULL;
}

void	*ft_free_mtrx(char **mtrx)
{
	int	i;

	i = 0;
	if (!mtrx)
		return (NULL);
	while (mtrx[i])
		free(mtrx[i++]);
	free(mtrx);
	return (NULL);
}

void	ft_free_and_exit(t_data *data)
{
	if (data->mtrx)
		ft_free_mtrx(data->mtrx);
	if (data->stack_a)
		ft_free_stack(&data->stack_a);
	if (data->stack_b)
		ft_free_stack(&data->stack_b);
	free(data);
	write(2, "Error\n", 6);
	exit (1);
}
