#include "main.h"

/**
 * print_specifier - Handle the printing of conversion specifiers.
 * @specifier: The conversion specifier character.
 * @args: The variable argument list.
 * @count: Pointer to the count of characters printed.
 */
void print_specifier(char specifier, va_list args, int count)
{
	switch (specifier)
	{
		case 'c':
			putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			count += printf("%s", va_arg(args, char *));
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
}

/**
 * str_len - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */

int str_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
