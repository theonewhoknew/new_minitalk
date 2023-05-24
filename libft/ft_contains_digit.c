#include "libft.h"

int	ft_contains_digit(char *str)
{
	while (*str)
	{	
		if (ft_isdigit(*str) == 0 && *str != ' ' && *str != '\"')
			return (0);
		str++;
	}
	return (1);
}