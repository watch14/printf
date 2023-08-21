#include "main.h"
/**
 * _printf - Prints formatted output to the standard output stream.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int nbch = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			nbch = check(*format, args, count);
		}
		else
		{
			putchar(*format);
			nbch++;
		}
		format++;
	}

	va_end(args);

	return (nbch);
}
