#include "main.h"

/**
 * check - Handles the printing of conversion specifiers.
 * @specifier: The conversion specifier character.
 * @args: The variable argument list.
 * @count: The count of characters printed.
 *
 * Return: The updated count of characters printed.
 */

int check(char specifier, va_list args, int count)
{
	switch (specifier)
	{
		case 'c':
			putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
				}
			}
			break;
		case '%':
			putchar('%');
			count++;
			break;
		case 'i':
		case 'd':
			count += printf("%d", va_arg(args, int));
			break;
		default:
			putchar('%');
			putchar(specifier);
			count += 2;
			break;
	}
	return (count);
}
