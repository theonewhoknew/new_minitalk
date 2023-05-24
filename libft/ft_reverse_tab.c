#include "libft.h"

void ft_reverse_tab(int *tab, int n) 
{
	int *first;
	int *last;
	int temp;
	
	first = tab;
    last = tab + (n - 1);

    while (first < last) 
	{
        temp = *first;
        *first = *last;
        *last = temp;
        first++;
        last--;
    }
}