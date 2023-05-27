/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:04:52 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:08:48 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*to_binary(int number)
{	
	int	c;
	int	*binary;
	int	i;

	i = 0;
	c = count_numbers(number);
	binary = (int *)malloc(sizeof (int) * 8);
	if (!binary)
		return (NULL);
	pad(binary, 8 - c);
	while (i < c)
	{
		if (number % 2 == 0)
			binary[i] = 0;
		else
			binary[i] = 1;
		i++;
		number /= 2;
	}
	ft_reverse_tab(binary, 8);
	return (binary);
}

void	send_signals(int *binary, char *pid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (binary[i] == 0)
		{
			kill(ft_atoi(pid), SIGUSR1);
		}
		else
		{
			kill(ft_atoi(pid), SIGUSR2);
		}
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{	
	int	decimal;
	int	count;
	int	*binary;
	int	i;

	i = 0;
	if (argc != 3)
		return (0);
	while (argv[2][i])
	{	
		decimal = argv[2][i];
		count = count_numbers(decimal);
		binary = to_binary(decimal);
		if (!binary)
			return (0);
		send_signals(binary, argv[1], 8);
		free (binary);
		binary = NULL;
		i++;
	}
	return (0);
}
