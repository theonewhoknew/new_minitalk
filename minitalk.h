/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:09:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/27 17:09:51 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "printf_nolib/ft_printf.h"

int		count_numbers(int number);
void	swap(int *binary, int number, int i, int c);
void	pad(int *binary, int pad);

#endif