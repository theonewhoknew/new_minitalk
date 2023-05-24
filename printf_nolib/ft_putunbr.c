/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:27:07 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/17 11:10:43 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"
#include <stdlib.h>

static size_t ft_num_len(unsigned long number)
{	
	size_t len;

	len = 1;
	while (number / 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

size_t	ft_putunbr(unsigned int n)
{
	unsigned long	number;
	size_t	count;
	size_t	len;
	char *str;
	
	count = 0;
	number = (unsigned long) n;
	len = ft_num_len(number);
	str = (char *)malloc(sizeof (char) * (len + 1));
	str[len] = '\0';
	if (number == 0)
		str[len - 1] = '0';
	while (number > 0)
	{
		str[len - 1] = number % 10 + '0';
		number /= 10;
		len--;
	}
	count = ft_putstr(str);
	free (str);
	str = NULL;
	return (count);
}
