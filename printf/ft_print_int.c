/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 11:02:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int i)
{
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_print_int(i / 10);
		ft_print_int(i % 10);
	}
	else
	{
		i += 48;
		write(1, &i, 1);
	}
}

void	ft_print_u_int(unsigned int i)
{
	if (i > 9)
	{
		ft_print_int(i / 10);
		ft_print_int(i % 10);
	}
	else
	{
		i += 48;
		write(1, &i, 1);
	}
}
