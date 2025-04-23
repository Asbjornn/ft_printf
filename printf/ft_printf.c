/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:06 by gcauchy           #+#    #+#             */
/*   Updated: 2025/04/23 11:02:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_type(char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		ft_print_int(va_arg(arg, int));
	else if (c == 'u')
		ft_print_u_int(va_arg(arg, unsigned int));
	else if (c == 's')
		ft_print_string(va_arg(arg, char *));
	else if (c == 'c')
		ft_print_char(va_arg(arg, int));
	else if (c == 'p')
		ft_print_address(va_arg(arg, void *));
	else if (c == 'x' || c == 'X')
		ft_print_hexa(va_arg(arg, int), c);
	else if (c == '%')
		ft_print_char('%');
}

static void	get_letter(char c)
{
	if (c == 'n')
		write(1, "\n", 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			get_type(s[i], args);
		}
		else if (s[i] == '\'')
		{
			i++;
			get_letter(s[i]);
		}
		else
			ft_print_char(s[i]);
		i++;
	}
	va_end(args);
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	void	*ptr;
// 	int		i;

// 	i = 0;
// 	ptr = &i;
// 	ft_printf("Bonjour je test printf\n");
// 	ft_printf("Les test\n");
// 	ft_printf("int avec d -> %d\n", 578);
// 	ft_printf("int avec i -> %i\n", 682);
// 	ft_printf("string -> %s\n", "Je suis un string");
// 	ft_printf("char -> %c\n", 'c');
// 	ft_printf("base 16 minuscule -> %x\n", 255);
// 	ft_printf("base 16 majuscule -> %X\n", 16);
// 	ft_printf("pointeur -> %p\n", ptr);
// 	printf("real function : %p\n", ptr);
// 	return (0);
// }
