/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:29:14 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:29:42 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_num_len(unsigned long number)
{	
	size_t	len;

	len = 1;
	while (number / 16)
	{
		number /= 16;
		len++;
	}
	return (len);
}

size_t	ft_puthexnbr(unsigned int n, char *base)
{
	unsigned long	number;
	size_t			count;	
	size_t			len;
	char			*str;

	count = 0;
	number = (unsigned long ) n;
	len = ft_num_len(number);
	str = (char *)malloc(sizeof (char) * (len + 1));
	str[len] = '\0';
	if (number == 0)
		str[len - 1] = '0';
	while (number > 0)
	{
		str[len - 1] = base[number % 16];
		number /= 16;
		len--;
	}
	count = ft_putstr(str);
	free (str);
	str = NULL;
	return (count);
}
