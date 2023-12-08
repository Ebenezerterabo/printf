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
	int count = 0, rev_num = 0;

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

void print_binary(va_list ap)
{
	int idx, i;
	unsigned int num = va_arg(ap, unsigned long);

	int *num_bits = malloc(sizeof(int) * 8 * sizeof(unsigned long int));

	if (num_bits == NULL)
		return;

	if (num == 0)
	{
		_putchr('0');
		free(num_bits);
		return;
	}

	for (idx = 0; num > 0; num /= 2)
	{
		num_bits[idx] = num % 2;
		idx++;
	}

	for (i = idx - 1; i >= 0; i--)
		_putchr(num_bits[i] + '0');

	free(num_bits);
}
