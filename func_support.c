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

	if (*str != '\0')
		write(1, str, _strlen(str));
	else
		write(1, "(nil)", 5);

	return (_strlen(str));
}

int _strlen(char *str)
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
	return(write(1, &c, 1));
}

/**
 * put_int - A function that prints an integer
 * @num: the number
 *
 * Return: an integer
 */

int put_int(int num)
{
	int count = 0, temp = num;

	if (num < 0)
	{
		_putchr('-');
		count++;
		num = - num;
	}

	while (temp / 10 != 0)
	{
		temp /= 10;
		count++;
	}

	if (num / 10 != 0)
		put_int(num / 10);
	_putchr(num % 10 + '0');

	return (count);
}
