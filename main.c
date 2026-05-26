/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:55:21 by rumartin          #+#    #+#             */
/*   Updated: 2026/05/26 22:16:55 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		ft_printf("El argumento introducido es es: %s", argv[1]);
	}
	else
	{
		ft_printf("No hay argumentos validos");
	}
	return (0);
}
