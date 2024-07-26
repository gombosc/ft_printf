/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgombos <cgombos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:29:10 by cgombos           #+#    #+#             */
/*   Updated: 2024/07/26 19:26:11 by cgombos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(args, int), 10, 0);
	else if (specifier == 'x')
		count += print_digit(va_arg(args, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit(va_arg(args, unsigned int), 16, 1);
	else if (specifier == 'u')
		count += print_unsigned(va_arg(args, unsigned int), 10);
	else if (specifier == 'p')
		count += print_ptr(va_arg(args, unsigned long long));
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
	int		n = 42;
	printf("Hello pointer, %p\n", &n);
	ft_printf("Hello custom pointer, %p\n", &n);
	ft_printf("Hello, %d\n", -122);
	ft_printf("Hello, %%\n", -32);
	ft_printf("Hello, %x\n", -422);
	printf("Hello, %u\n", 422);
	ft_printf("Hello, %u\n", 422);
	return (0);
}
