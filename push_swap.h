/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/28 17:58:06 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerias
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Estructuras
typedef struct stack
{
	int				number;
	struct stack	*next;
	struct stack	*prev;
}					t_node;

typedef struct s_data
{
	int				strategy; //Pensar en cambiar por un enum
	int				bench;
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
}					t_data;


// Prototipos
int	ft_args_checker(int argc, char **argv, t_data *data);
int	ft_stack_add_back(t_node **stack, int size, int number);
long long	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);

#endif