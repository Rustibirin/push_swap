/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/31 13:39:44 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerias
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Estructuras

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef enum e_bench
{
	NO,
	YES
}	t_bench;

typedef struct stack
{
	int				number;
	struct stack	*next;
	struct stack	*prev;
}					t_node;

typedef struct s_data
{
	t_strategy		strategy;
	t_bench			bench;
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
}					t_data;

// Prototipos
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);
int		ft_args_checker(char **argv, t_data *data);
int		ft_stack_add_back(t_node **stack, int *size, int number);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	*ft_free_mtrx(char **mtrx, size_t id);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_stack(t_node **stack);
void	rotate(t_node **stack);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	swap(t_node **stack);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	reverse_rotate(t_node **stack);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	push(t_node **stack_src, t_node **stack_dest);
void	pa(t_data *data);
void	pb(t_data *data);

#endif