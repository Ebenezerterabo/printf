#include "main.h"

/**
 * print_char - A function that prints a character
 * @ap: argument pointer
 *
 * Return: an integer
 */

int print_char(va_list ap)
{
	char ch = va_arg(ap, int);

	write(1, &ch, 1);
	return (1);
}

/**
 * print_str - A function that prints a character
 * @ap: argument pointer
 *
 * Return: an integer
 */

int print_str(va_list ap)
{
	char *str = va_arg(ap, char*);

	int len, i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}

	len = _strlen(str);

		while (i != len)
		{
			_putchr(str[i]);
			i++;
		}

	return (len);
}

/**
 * _strlen - calculate the lenght of the string
 * @str: string char
 * Return: - 1 on success
 */

int _strlen(const char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * _putchr - A function that prints a character
 * @c: the character
 *
 * Return: integer
 */

int _putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

