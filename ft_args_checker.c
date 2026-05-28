/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:27:26 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/28 11:39:04 by rumartin         ###   ########.fr       */
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
			break ;
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

static	int	ft_fill_stack(char **argv, t_data *data)
{
	int			i;
	long long	number_long;
	int			number;

	i = data->start_i;
	while (argv[i])
	{
		if (ft_valid_num(argv[i]))
			return (1);
		number_long = ft_atoi(argv[i]);
		if (number_long > INT_MAX || number_long < INT_MIN)
			return (1);
		number = number_long;
		if (ft_check_duplicate(data->stack_a, number))
			return (1);
		if (ft_stack_add_back(&data->stack_a, number))
			return (1);
		i++;
	}
	return (0);
}

int	ft_args_checker(int argc, char **argv, t_data *data)
{
	data->start_i = 2;
	data->bench = 0;
	if (argv[1] && (ft_strncmp(argv[1], "--simple", 9) == 0))
		data->strategy = 1;
	else if (argv[1] && (ft_strncmp(argv[1], "--medium", 9) == 0))
		data->strategy = 2;
	else if (argv[1] && (ft_strncmp(argv[1], "--complex", 10) == 0))
		data->strategy = 3;
	else if (argv[1] && (ft_strncmp(argv[1], "--adaptive", 11) == 0))
		data->strategy = 4;
	else if (argv[1] && (ft_strncmp(argv[1], "--benchmark", 12) == 0))
	{
		data->strategy = 4;
		data->bench = 1;
	}
	else
	{
		data->strategy = 4;
		data->start_i = 1;
	}
	if (ft_fill_stack(argv, data))
		return (1);
	return (0);
}
