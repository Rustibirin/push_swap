/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:03:47 by framirez          #+#    #+#             */
/*   Updated: 2026/05/28 20:01:31 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_src, t_node **stack_dest, int size_1, int size_2)
{
	t_node	*aux_1;
	t_node	*aux_2;
	t_node	*aux_aux;

	if (stack_src == NULL || *stack_src == NULL)
		return ;
	else
	{
		aux_1 = *stack_1;          // guardo el primer nodo
		aux_2 = *stack_2;          // guardo el segundo nodo
		aux_1->prev->next = aux_2; // control de extremos
		aux_2->prev->next = aux_1; // control de extremos
		aux_1->next->prev = aux_2; // control de extremos
		aux_2->next->prev = aux_1; // control de extremos
		aux_aux = aux_2->prev;     // empieza el bloque de los prev
		aux_2->prev = aux_1->prev;
		aux_1->prev = aux_aux;
		aux_aux = aux_2->next; // empieza el bloque de los next
		aux_2->next = aux_1->next;
		aux_1->next = aux_aux;
		*stack_1 = aux_2;
		*stack_2 = aux_1;
	}
}
