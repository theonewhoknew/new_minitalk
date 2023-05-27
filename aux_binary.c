/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:03:36 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:04:13 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	count_numbers(int number)
{
	int	c;

	c = 0;
	while (number > 0)
	{	
		number /= 2;
		c++;
	}
	return (c);
}

void	swap(int *binary, int number, int i, int c)
{
	while (i < c)
	{
		if (number % 2 == 0)
			binary[i] = 0;
		else
			binary[i] = 1;
		i++;
		number /= 2;
	}
}

void	pad(int *binary, int pad)
{	
	int	i;

	i = 7;
	while (pad)
	{
		binary[i] = 0;
		i--;
		pad--;
	}
}
