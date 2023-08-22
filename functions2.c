#include "main.h"

/**
 * check_b - Prints an unsigned integer in binary format.
 * @args: The variable argument list.
 * @count: The current count of characters printed.
 * Return: The updated count of characters printed.
 */

int check_b(va_list args, int count)
{
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		char c = '0';

		write(1, &c, 1);
		count++;
	}
	else if (n == 1)
	{
		char c = '1';

		write(1, &c, 1);
		count++;
	}
	else
	{
		char binary[32];
		int i = 0;

		while (n > 0)
		{
			binary[i] = (n % 2) + '0';
			n /= 2;
			i++;
		}

		while (i > 0)
		{
			i--;
			write(1, &binary[i], 1);
			count++;
		}
	}

	return (count);
}
