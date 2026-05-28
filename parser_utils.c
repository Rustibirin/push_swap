/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 09:49:14 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/28 11:41:37 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_add_back(t_node **stack, int number)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->number = number;
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		last_node = (*stack)->prev; // Guardamos el uĺtimo nodo (el previo al primero).
		last_node->next = new_node; // Hacemos que ese ultimo apunte a este nuevo ultimo.
		new_node->prev = last_node; // Hacemos que este ultimo apunte a ese antiguo ulitmo.
		new_node->next = *stack; // Hacemos que este nuevo ultimo apunte al primero del stack.
		(*stack)->prev = new_node; // Hacemos que el primero del stack apunte a este nuevo ultimo.
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	number;
	int			sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t		i;
	size_t		total;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (total--)
		ptr[i++] = 0;
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
