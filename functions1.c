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
 * check_c - Handle conversion specifier 'c'.
 * @args: The variable argument list.
 * @count: The current count of characters printed.
 *
 * Return: The updated count of characters printed.
 */

int check_c(va_list args, int count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	count++;
	return (count);
}


/**
 * check_s - Handle conversion specifier 's'.
 * @args: The variable argument list.
 * @count: The current count of characters printed.
 *
 * Return: The updated count of characters printed.
 */

int check_s(va_list args, int count)
{
	char *str = va_arg(args, char *);

	count += write(1, str, strlen(str));
	return (count);
}

/**
 * check_d - Handle conversion specifier 'd' and 'i'.
 * @args: The variable argument list.
 * @count: The current count of characters printed.
 *
 * Return: The updated count of characters printed.
 */

int check_d(va_list args, int count)
{
	char buffer[20];
	int n = snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));

	if (n > 0)
	{
		count += write(1, buffer, n);
	}
	return (count);
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
			count = check_c(args, count);
			break;
		case 's':
			count = check_s(args, count);
			break;
		case '%':
			write(1, "%", 1);
			count++;
			break;
		case 'i':
		case 'd':
			count = check_d(args, count);
			break;
		default:
			write(1, "%", 1);
			write(1, &specifier, 1);
			count += 2;
			break;
	}
	return (count);
}
