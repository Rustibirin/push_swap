/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumartin <rumartin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:43:53 by rumartin          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:01 by rumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Librerias
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

// Prototipos
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_putchar(const int c);
int		ft_putstr(char *str);
int		ft_putpointer(void *ptr);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(int c, uintptr_t n);

#endif
