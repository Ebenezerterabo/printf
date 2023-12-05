#include "main.h"

/**
 * _printf - A custom printf function
 * @format: the string argument
 *
 * Return: the total number of characters
 */

int _printf(const char *format, ...)
{
	int total_char = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			total_char += check_cases(ap, format);
		}
		else
		{
			write(1, format, 1);
			total_char++;
		}

		format++;
	}
	va_end(ap);
	return (total_char);
}
