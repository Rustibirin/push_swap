/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:58:20 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/17 17:54:23 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	// Libraries

# include "ftprintf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

	// Structures

typedef struct s_vars
{
	int				middle;
	int				ra_times;
	int				rb_times;
	int				pa_times;
	int				pb_times;
}					t_complex_vars;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE_SIMPLE,
	ADAPTIVE_MEDIUM,
	ADAPTIVE_COMPLEX
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
	size_t			total_ops;
	char			**mtrx;
	int				size_a;
	int				size_b;
	int				rep_strategy;
	int				rep_bench;		
	double			dis_index;
}					t_data;

	// Prototypes

// parser.c

void				ft_args_checker(char **argv, t_data *data);

// parser_utils.c

int					ft_stack_add_back(t_node **stack, int *size, int number);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
long				ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);

// split.c

char				**ft_split(t_data *data, char const *s, char c);

// split_utils.c

char				*ft_substr(char const *s, unsigned int start, size_t len);

// simple.c

int					ft_simple(t_data *data);

// medium.c

int					ft_medium(t_data *data);

// complex.c

int					ft_complex(t_data *data);
int					ft_quicksort_a(t_data *data, int size);
int					ft_quicksort_b(t_data *data, int size);

// complex_utils.c

int					ft_rewind_a(t_data *data, int ra_times);
int					ft_rewind_b(t_data *data, int rb_count);
int					ft_sort_small_a(t_data *data, int size);
int					ft_sort_small_b(t_data *data, int size);
void				ft_fill_array(t_node *stack, int *arr, int size);

// algorithms_utils.c

int					ft_sqrt(int num);
void				ft_min_extraction(t_data *data);
void				ft_sort_puppy(t_data *data);
void				ft_sort_three(t_data *data);

// swap.c

int					sa(t_data *data);
int					sb(t_data *data);
int					ss(t_data *data);

// push.c

int					pa(t_data *data);
int					pb(t_data *data);

// rotate.c

int					ra(t_data *data);
int					rb(t_data *data);
int					rr(t_data *data);

// reverse_rotate.c

int					rra(t_data *data);
int					rrb(t_data *data);
int					rrr(t_data *data);

// bench.c

void				ft_bench(t_data *data);

// errors.c

void				ft_free_stack(t_node **stack);
void				*ft_free_mtrx(char **mtrx);
void				ft_free_and_exit(t_data *data);

#endif
