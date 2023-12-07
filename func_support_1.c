#include "main.h"

/**
 * put_int - A function that prints integers
 * @ap: argument pointer
 *
 * Return: total numbers printed
 */

int put_int(va_list ap)
{
	long rev_num = 0, temp;
	int count = 0, num;

	num = va_arg(ap, int);

	if (num == INT_MIN)
	{
		_putchr('-');
		count++;
		rev_num = -(num % 10);
		num /= 10;
		num = -num;
	}

	if (num < 0)
	{
		_putchr('-');
		count++;
		num = -(num);
	}

	if (num == 0)
	{
		putchr('0');
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
