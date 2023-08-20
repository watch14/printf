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

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				nbch++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				write(1, s, str_len(s));
				nbch += str_len(s);
			}
		} else
		{
			write(1, &format[i], 1);
			nbch++;
		}
	}
	va_end(args);
	return (nbch);
}
