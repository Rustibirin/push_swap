/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/02 23:23:00 by rumartin         ###   ########.fr       */
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
	char			**mtrx;
	int				size_a;
	int				size_b;
	double			dis_index;
}					t_data;

// Prototipos
char	**ft_split(t_data *data, char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);
int		ft_stack_add_back(t_node **stack, int *size, int number);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_simple(t_data *data);
int		ft_medium(t_data *data);
int		ft_complex(t_data *data);
int		ft_adaptive(t_data *data);
void		ft_args_checker(char **argv, t_data *data);
void	*ft_free_mtrx(char **mtrx);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_stack(t_node **stack);
void	ft_bench(t_data *data);
void	ft_free_and_exit(t_data *data);
int		rotate(t_node **stack);
int		ra(t_data *data);
int		rb(t_data *data);
int		rr(t_data *data);
int		swap(t_node **stack);
int		sa(t_data *data);
int		sb(t_data *data);
int		ss(t_data *data);
int		reverse_rotate(t_node **stack);
int		rra(t_data *data);
int		rrb(t_data *data);
int		rrr(t_data *data);
int		push(t_node **stack_src, t_node **stack_dest);
int		pa(t_data *data);
int		pb(t_data *data);


#endif
