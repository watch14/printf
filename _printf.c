#include "main.h"
/**
 * _printf - Prints formatted output to the standard output stream.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i, nbch = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			char *s = va_arg(args, char *);

			nbch = check(format[i], s, nbch);
		}
		else
		{
			write(1, &format[i], 1);
			nbch++;
		}
	}
	va_end(args);
	return (nbch);
}
