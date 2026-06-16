/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:27:26 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/16 12:38:18 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check_duplicate(t_node *stack, int number)
{
	t_node	*act_node;

	if (!stack)
		return (0);
	if (stack->number == number)
		return (1);
	act_node = stack->next;
	while (act_node != stack)
	{
		if (act_node->number == number)
			return (1);
		act_node = act_node->next;
	}
	return (0);
}

static	int	ft_valid_num(char *str)
{
	int	i;

	if (!str)
		return (1);
	if (str[0] != '+' && str[0] != '-' && (str[0] < '0' || str[0] > '9'))
		return (1);
	if (str[1] == '\0' && (str[0] == '+' || str[0] == '-'))
		return (1);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_detect_flag(char *str, t_data *data)
{
	if (str && (ft_strncmp(str, "--adaptive", 11) == 0))
		return (data->rep_strategy += 1, data->strategy = ADAPTIVE, 0);
	if (str && (ft_strncmp(str, "--simple", 9) == 0))
		return (data->rep_strategy += 1, data->strategy = SIMPLE, 0);
	if (str && (ft_strncmp(str, "--medium", 9) == 0))
		return (data->rep_strategy += 1, data->strategy = MEDIUM, 0);
	if (str && (ft_strncmp(str, "--complex", 10) == 0))
		return (data->rep_strategy += 1, data->strategy = COMPLEX, 0);
	if (str && (ft_strncmp(str, "--bench", 8) == 0))
		return (data->rep_bench += 1, data->bench = YES, 0);
	return (1);
}

static	int	ft_fill_stack(char *str, t_data *data)
{
	long	number_long;
	int		number;

	if (ft_detect_flag(str, data))
	{
		if (ft_valid_num(str))
			return (1);
		number_long = ft_atoi(str);
		if (number_long < INT_MIN || number_long > INT_MAX)
			return (1);
		number = number_long;
		if (ft_check_duplicate(data->stack_a, number))
			return (1);
		if (ft_stack_add_back(&data->stack_a, &data->size_a, number))
			return (1);
	}
	if (data->rep_strategy > 1  || data->rep_bench > 1)
			return (1);
	return (0);
}

void	ft_args_checker(char **argv, t_data *data)
{
	int		i;
	int		j;
	int		fail_fill;

	data->bench = NO;
	i = 1;
	while (argv[i])
	{
		data->mtrx = ft_split(data, argv[i], ' ');
		if (!data->mtrx[0])
			ft_free_and_exit(data);
		j = 0;
		while (data->mtrx[j])
		{
			fail_fill = ft_fill_stack(data->mtrx[j++], data);
			if (fail_fill)
			{
				ft_free_and_exit(data);
				return ;
			}
		}
		ft_free_mtrx(data->mtrx);
		i++;
	}
}
