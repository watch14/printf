#include "main.h"

/**
 * check_b - Prints an unsigned integer in binary format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int check_b(unsigned int n)
{
	if (n == 0)
	{
		putchar('0');
		return (1);
	}
	else if (n == 1)
	{
		putchar('1');
		return (1);
	}
	else
	{
		return (check_b(n / 2) + printf("%d", n % 2));
	}
}
