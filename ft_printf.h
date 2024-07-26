/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgombos <cgombos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:06:06 by cgombos           #+#    #+#             */
/*   Updated: 2024/07/26 19:12:13 by cgombos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // variadic functions va_start, va_arg, va_end
# include <unistd.h> // write
# include <stdlib.h> // malloc
# include <stdio.h> 
# include <limits.h> // INT_MIN, INT_MAX
# include <stdbool.h> // bool

int	ft_printf(const char *format, ...);
int	print_ch(int c);
int	print_str(char *str);
int	print_digit(long n, int base, int upper);
int	print_unsigned(unsigned long int n, int base);
int	print_ptr(unsigned long long ptr);

#endif