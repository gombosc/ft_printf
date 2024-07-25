/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgombos <cgombos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:29:10 by cgombos           #+#    #+#             */
/*   Updated: 2024/07/25 17:27:11 by cgombos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	print_ch(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	while (*str)
		print_ch(*str++);
	return (0);
}

int	print_digit(long n, int base, int upper)
{
	int		count;
	char	*symbols;

	if (upper)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, upper) + 1);
	}
	else if (n < base)
		return (print_ch(symbols[n]));
	else
	{
		count += print_digit(n / base, base, upper);
		return (count + print_digit(n % base, base, upper));
	}
}

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += print_ch('%');
	else if (specifier == 'c')
		count += print_ch(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'd')
		count += print_digit(va_arg(args, int), 10, 0);
	else if (specifier == 'x')
		count += print_digit(va_arg(args, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit(va_arg(args, unsigned int), 16, 1);	
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	// Testing cases

	ft_printf("Hello, %d\n", -122);

	ft_printf("Hello, %%\n", -32);
	ft_printf("Hello, %x\n", -422);
	return (0);
}