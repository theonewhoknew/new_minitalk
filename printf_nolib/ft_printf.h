/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:28:52 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/17 11:08:31 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>

size_t	check_conversions(va_list args, char const *str);
int		ft_printf(char const *str, ...);
size_t	ft_strlen(const char *s);
size_t	ft_putadd(void *ptr);
size_t	ft_putchar(char c);
size_t	ft_puthexnbr(unsigned int n, char *base);
size_t	ft_putnbr(int n);
size_t	ft_putstr(char *s);
size_t	ft_putunbr(unsigned int n);

#endif