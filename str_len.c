#incluide "main.h"

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
