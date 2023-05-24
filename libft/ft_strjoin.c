/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:34:00 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/09 09:35:20 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
*/
static size_t	ft_strlen(const char *s)
{
	unsigned int	c;

	c = 0;
	while (*s)
	{
		c++;
		s++;
	}
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*join;
	int			i;

	i = 0;
	len = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof (char) * (len + 1));
	if (!join)
		return (NULL);
	while (*s1)
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
/*
int main(void)
{
    char *s1 = "Hola";
    char *s2 = "Adios";
    char *join;

    join = ft_strjoin(s1, s2);
    printf("%s", join);   
}
*/