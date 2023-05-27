/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:10:08 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:17:22 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include <unistd.h>

void	process_bits(int signal)
{	
	static unsigned char	character;
	static int				bit_count;

	if (signal == SIGUSR1)
	{	
		character = (character << 1) | 0;
	}
	else if (signal == SIGUSR2)
	{	
		character = (character << 1) | 1;
	}
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(character, 1);
		character = 0;
		bit_count = 0;
	}
}

int	main(void)
{	
	struct sigaction	sa;
	sigset_t			sigset;

	sa.sa_handler = process_bits;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	ft_printf("%d\n", getpid());
	while (1)
		;
}
