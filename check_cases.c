#include "main.h"

/**
 * check_cases - A function that checks special characters
 * @format: the string argument
 * @ap: argument pointer
 *
 * Return: Nothing
 */

int check_cases(va_list ap, const char *format)
{
	int len = 0;

	if (*format == 'd' || *format == 'i')
	{
		len += put_int(ap);
	}
	else
	{

		switch (*format)
		{
		case 'c':
			len += print_char(ap);
			break;
		case 's':
			len += print_str(ap);
			break;
		case '%':
			len += _putchr('%');
			break;
		case 'b':
			len += print_binary(ap);
			break;
		case 'r':
			len += string_rev(ap);
			break;
		case 'R':
			print_rot13(ap);
		default:
			break;

		}
	}
	return (len);
}
