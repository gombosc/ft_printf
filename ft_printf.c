/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgombos <cgombos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:29:10 by cgombos           #+#    #+#             */
/*   Updated: 2024/07/23 18:16:46 by cgombos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	while (*str)
		ft_printchar(*str++);
}

int	ft_printint(int n, int base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_printchar('-');
		n *= -1;
	}
	if (n >= base)
		count += ft_printint(n / base, base);
	count += ft_printchar("0123456789abcdef"[n % base]);
	return (count);

}

int print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd')
		count += ft_printint(va_arg(args, int), 10);
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
		format++;
	}
	va_end(args);
	return (count);
}


int	main(void)
{
	ft_printf("Hello, %s", 42);
	return (0);
}