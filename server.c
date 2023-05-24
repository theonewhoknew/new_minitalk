#include <signal.h>
#include "minitalk.h"
#include <unistd.h>

void process_bits(int signal)
{	
	static unsigned char character;
	static int bit_count;

	if (signal == SIGUSR1)
	{	
		character = (character << 1) | 0;
	}
	else
	{	
		character = (character << 1) | 1;
	}
	bit_count++;
	if(bit_count == 8)
	{
		ft_putchar_fd(character, 1);
		character = 0;
		bit_count = 0;
	}
}

int main(void)
{	
	struct sigaction sa;

	sa.sa_handler = process_bits;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
	{
		
	}
}