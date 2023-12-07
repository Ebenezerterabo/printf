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
