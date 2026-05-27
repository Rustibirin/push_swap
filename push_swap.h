/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/27 23:04:08 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerias
# include <stdlib.h>
# include <unistd.h>

// Estructuras
typedef struct stack
{
	int				number;
	struct stack	*next;
	struct stack	*prev;
}					t_node;

typedef struct parser
{
	int			strategy; //Pensar en cambiar por un enum
	int			start_i;
	int			bench;
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
}				t_data;


// Prototipos
int	ft_args_checker(int argc, char **argv, t_data *data);

#endif