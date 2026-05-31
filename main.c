/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/31 13:38:54 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_node *stack)
{
	t_node	*act_node;

	if (!stack)
		return (0);
	act_node = stack;
	while (act_node->next != stack)
	{
		if (act_node->number > act_node->next->number)
			return (1);
		act_node = act_node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_checker(argv);
		printf("Hola");
	}
	return (0);
}
