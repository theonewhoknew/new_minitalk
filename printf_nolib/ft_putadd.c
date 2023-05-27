/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:28:29 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:29:04 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static size_t	ft_add_len(unsigned long temp, size_t len)
{
	while (temp > 15)
	{
		temp /= 16;
		len++;
	}
	return (len + 1);
}

static char	*ft_create_arr(char *str, unsigned long temp,
			unsigned long n, int i)
{
	while (i >= 0)
	{
		temp = n % 16;
		if (temp > 9)
			str[i] = temp + 87;
		else
			str[i] = temp + '0';
		n /= 16;
		i--;
	}
	return (str);
}

size_t	ft_putadd(void *ptr)
{
	size_t			len;
	unsigned long	n;
	unsigned long	temp;
	int				i;
	char			*str;

	len = 0;
	str = NULL;
	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (unsigned long int) ptr;
	temp = n;
	len = ft_add_len(temp, len);
	i = len - 1;
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	str = ft_create_arr(str, temp, n, i);
	n = ft_putstr("0x");
	n += ft_putstr(str);
	free (str);
	str = NULL;
	return (n);
}
