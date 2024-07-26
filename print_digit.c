/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgombos <cgombos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:14:46 by cgombos           #+#    #+#             */
/*   Updated: 2024/07/26 17:21:39 by cgombos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
