/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:01:56 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 11:02:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hexa(int i, char c)
{
	char	letter;

	if (i < 10)
	{
		letter = i + '0';
		write(1, &letter, 1);
	}
	else
	{
		if (c == 'x')
			letter = (i + 'a') - 10;
		else if (c == 'X')
			letter = (i + 'A') - 10;
		write(1, &letter, 1);
	}
}

static void	ft_print_hexa_add(unsigned long i, char c)
{
	unsigned long	temp[16];
	unsigned long	count;

	count = 0;
	if (i == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (i > 0)
	{
		temp[count] = i % 16;
		i /= 16;
		count++;
	}
	while (count-- > 0)
		ft_write_hexa(temp[count], c);
}

void	ft_print_address(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_print_string("0x");
	if (addr == 0)
		ft_print_char('0');
	else
		ft_print_hexa_add(addr, 'x');
}
