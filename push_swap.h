/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framirez <framirez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 17:12:35 by framirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerias

# include "ftprintf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// Estructuras

typedef struct s_vars
{
	int				middle;
	int				ra_count;
	int				rb_count;
	int				pa_count;
	int				pb_count;
}					t_complex_vars;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

typedef enum e_bench
{
	NO,
	YES
}					t_bench;

typedef struct stack
{
	int				number;
	int				index;
	struct stack	*next;
	struct stack	*prev;
}					t_node;

typedef struct s_data
{
	t_strategy		strategy;
	t_bench			bench;
	t_node			*stack_a;
	t_node			*stack_b;
	size_t			sa_cnt;
	size_t			sb_cnt;
	size_t			ss_cnt;
	size_t			pa_cnt;
	size_t			pb_cnt;
	size_t			ra_cnt;
	size_t			rb_cnt;
	size_t			rr_cnt;
	size_t			rra_cnt;
	size_t			rrb_cnt;
	size_t			rrr_cnt;
	size_t			total_moves;
	char			**mtrx;
	int				size_a;
	int				size_b;
	double			dis_index;
}					t_data;

// Prototipos
char				**ft_split(t_data *data, char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
long				ft_atoi(const char *str);
int					ft_stack_add_back(t_node **stack, int *size, int number);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					ft_simple(t_data *data);
int					ft_medium(t_data *data);
int					ft_complex(t_data *data);
void				ft_args_checker(char **argv, t_data *data);
void				*ft_free_mtrx(char **mtrx);
void				*ft_calloc(size_t count, size_t size);
void				ft_free_stack(t_node **stack);
void				ft_bench(t_data *data);
void				ft_free_and_exit(t_data *data);
void				ft_sort_three(t_data *data);
void				ft_fill_array(t_node *stack, int *arr, int size);
int					ft_quicksort_a(t_data *data, int size);
int					ft_quicksort_b(t_data *data, int size);
int					ft_rewind_a(t_data *data, int ra_count);
int					ft_rewind_b(t_data *data, int rb_count);
int					ft_sort_small_a(t_data *data, int size);
int					ft_sort_small_b(t_data *data, int size);
int					rotate(t_node **stack);
int					ra(t_data *data);
int					rb(t_data *data);
int					rr(t_data *data);
int					swap(t_node **stack);
int					sa(t_data *data);
int					sb(t_data *data);
int					ss(t_data *data);
int					reverse_rotate(t_node **stack);
int					rra(t_data *data);
int					rrb(t_data *data);
int					rrr(t_data *data);
int					push(t_node **stack_src, t_node **stack_dest);
int					pa(t_data *data);
int					pb(t_data *data);
int					ft_sqrt(int num);

#endif
