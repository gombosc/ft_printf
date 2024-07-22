Can use: malloc, free, write, va_start, va_arg, va_copy, va_end

Variadic functions - accept a variable nr of arguments
#include <stdarg.h>
va_list, va_start, va_arg, va_end


The prototype of ft_printf() is:
int ft_printf(const char *, ...);

You have to implement the following conversions (cspdiuxX%)
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign


1) Makefile and a header file with all the functions you will use.