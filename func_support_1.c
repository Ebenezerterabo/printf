#include "main.h"

/**
 * put_int - A function that prints integers
 * @ap: argument pointer
 *
 * Return: total numbers printed
 */

int put_int(va_list ap)
{
	int rev_num, temp, count = 0;
	int num;

	num = va_arg(ap, int);

	if (num < 0)
	{
		_putchr('-');
		count++;
		num = -num;
	}

	if (num == 0)
	{
		_putchr('0');
		count++;
	}
	else
	{
		while (num != 0)
		{
			temp = num % 10;
			rev_num = rev_num * 10 + temp;
			num /= 10;
		}

		while (rev_num != 0)
		{
			temp = rev_num % 10;
			_putchr(temp + '0');
			count++;
			rev_num /= 10;
		}
	}

	return (count);

}
