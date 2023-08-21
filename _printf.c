#include "main.h"
/**
 * _printf - Prints formatted output to the standard output stream.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_specifier(*format, args, count);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	rieturn (count);

}
