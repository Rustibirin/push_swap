/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:27:26 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/29 14:51:52 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check_duplicate(t_node *stack_a, int number)
{
	t_node	*act_node;

	if (!stack_a)
		return (0);
	act_node = stack_a;
	while (1)
	{
		if (act_node->number == number)
			return (1);
		act_node = act_node->next;
		if (act_node == stack_a)
			return (0);
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
	if (str && (ft_strncmp(str, "--simple", 9) == 0))
		return (data->strategy = SIMPLE, 0);
	if (str && (ft_strncmp(str, "--medium", 9) == 0))
		return (data->strategy = MEDIUM, 0);
	if (str && (ft_strncmp(str, "--complex", 10) == 0))
		return (data->strategy = COMPLEX, 0);
	if (str && (ft_strncmp(str, "--adaptive", 11) == 0))
		return (data->strategy = ADAPTIVE, 0);
	if (str && (ft_strncmp(str, "--bench", 8) == 0))
		return (data->bench = YES, 0);
	return (1);
}

static	int	ft_fill_stack(char **argv, t_data *data)
{
	int		i;
	long	number_long;
	int		number;

	i = 1;
	while (argv[i])
	{
		if (ft_detect_flag(argv[i], data))
		{
			if (ft_valid_num(argv[i]))
				return (1);
			number_long = ft_atoi(argv[i]);
			if (number_long > INT_MAX || number_long < INT_MIN)
				return (1);
			number = number_long;
			if (ft_check_duplicate(data->stack_a, number))
				return (1);
			if (ft_stack_add_back(&data->stack_a, &data->size_a, number))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_args_checker(char **argv, t_data *data)
{
	data->bench = NO;
	data->strategy = ADAPTIVE;
	if (ft_fill_stack(argv, data))
		return (1);
	return (0);
}
