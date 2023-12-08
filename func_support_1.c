#include "main.h"

/**
 * put_int - A function that prints integers
 * @ap: argument pointer
 *
 * Return: total numbers printed
 */

int put_int(va_list ap)
{
	long num = (long)va_arg(ap, int);
	long count = 0, rev_num = 0;

	if (num < 0)
	{
		_putchr('-');
		count++;
		num = -(num);
	}

	if (num == 0)
	{
		_putchr('0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			rev_num = rev_num * 10 + num % 10;
			num /= 10;
		}

		while (rev_num > 0)
		{
			_putchr(rev_num % 10 + '0');
			count++;
			rev_num /= 10;
		}
	}

	return (count);
}

/**
 * print_binary - A function to print binary representation of an integer
 * @ap: argument pointer
 *
 * Return: binary number
 */

int print_binary(va_list ap)
{
	int idx, i, count = 0;
	unsigned int num = va_arg(ap, unsigned long);

	int *num_bits = malloc(sizeof(int) * 8 * sizeof(unsigned long int));

	if (num_bits == NULL)
		return (-1);

	if (num == 0)
	{
		_putchr('0');
		free(num_bits);
		return (0);
	}

	for (idx = 0; num > 0; num /= 2)
	{
		num_bits[idx] = num % 2;
		idx++;
	}

	for (i = idx - 1; i >= 0; i--)
	{
		_putchr(num_bits[i] + '0');
		count++;
	}

	free(num_bits);

	return (count);
}

/**
 * string_rev - A function that reverses a string
 * @ap: string
 *
 * Return: number of characters printed
 */

int string_rev(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, len = 0;

	while (str[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
		_putchr(str[i]);

	return (len);
}

/**
 * print_rot13 - A function that encodes a string using rot13
 * @ap: argument pointer
 *
 * Return: a pointer to the string
 */

int print_rot13(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, j;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rev[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int print, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		print = 0;

		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (str[i] == alpha[j])
			{
				_putchr(rev[j]);
				count++;
				print = 1;
				break;
			}
		}

		if (!print)
		{
			_putchr(str[i]);
			count++;
		}
	}

	return (count);
}
