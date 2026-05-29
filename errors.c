/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:20:22 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 11:22:29 by rumartin         ###   ########.fr       */
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
	act_node = *stack;
	while (1)
	{
		next_node = act_node->next;
		free(act_node);
		act_node = next_node;
		if (act_node == first_node)
			return (*stack = NULL);
	}
}
