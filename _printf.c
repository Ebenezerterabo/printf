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

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			while (*(format + 1) == ' ')
				format++;

			format++;

			if (*format == '\0' || *format == ' ')
				return (-1);

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
