#include "libft.h"

void ft_printarr(int *arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
