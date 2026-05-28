/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:20:22 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/28 11:41:57 by rumartin         ###   ########.fr       */
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
		next_node = act_node->next; // Guardamos la direccion al siguiente nodo.
		free(act_node);				// Liberamos el nodo actual.
		act_node = next_node;		// Pasamos al siguiente nodo.
		if (act_node == first_node)	// Si es el primer nodo, salimos.
			break ;
	}
	*stack = NULL;					// Dejamos el stack apuntando a NULL para evitar errores futuros.
}
