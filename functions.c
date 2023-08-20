#incluide "main.h"
/**
 * check - Handles different format specifiers.
 * @f: The format specifier.
 * @s: The string argument.
 * @nbch: The current number of characters printed.
 *
 * Return: The updated number of characters printed.
 */

int check(char f, char *s, int nbch)
{
	if (f == 'c')
	{
		write(1, s, 1);
		nbch++;
	}
	else if (f == 's')
	{
		write(1, s, str_len(s));
		nbch += str_len(s);
	}
	else if (f == '%')
	{
		char c = '%';

		write(1, &c, 1);
		nbch++;
	}
	return (nbch);
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
/**
 * print_specifier - Handle the printing of conversion specifiers.
 * @specifier: The conversion specifier character.
 * @args: The variable argument list.
 * @count: Pointer to the count of characters printed.
 */
void print_specifier(char specifier, va_list args, int *count)
{
	switch (specifier)
	{
		case 'c':
			putchar(va_arg(args, int));
			(*count)++;
			break;
		case 's':
			(*count) += printf("%s", va_arg(args, char *));
			break;
		case '%':
			putchar('%');
			(*count)++;
			break;
		case 'i':
		case 'd':
			(*count) += printf("%d", va_arg(args, int));
			break;
		default:
			putchar('%');
			putchar(specifier);
			(*count) += 2;
			break;
	}
}
