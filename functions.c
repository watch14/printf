#include "main.h"

/**
 * str_len - Calculate the length of a string.
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
		case 'b':
			count += print_binary(va_arg(args, int));
			break;
		default:
			putchar('%');
			putchar(specifier);
			count += 2;
			break;
	}
	return (count);
}
