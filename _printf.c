#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str_arg;
	unsigned int uint_arg;
	int int_arg;
	char char_arg;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					char_arg = va_arg(args, int);
					_putchar(char_arg);
					printed_chars++;
					break;

				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					printed_chars += _puts(str_arg);
					break;

				case '%':
					_putchar('%');
					printed_chars++;
					break;

				case 'd':
				case 'i':
					int_arg = va_arg(args, int);
					printed_chars += print_number(int_arg);
					break;

				case 'u':
					uint_arg = va_arg(args, unsigned int);
					printed_chars += print_unsigned_number(uint_arg);
					break;

				case 'o':
					uint_arg = va_arg(args, unsigned int);
					printed_chars += print_octal_number(uint_arg);
					break;

				case 'x':
					uint_arg = va_arg(args, unsigned int);
					printed_chars += print_hex_number(uint_arg, 0);
					break;

				case 'X':
					uint_arg = va_arg(args, unsigned int);
					printed_chars += print_hex_number(uint_arg, 1);
					break;

				case 'S':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					printed_chars += print_special_string(str_arg);
					break;

				case 'p':
					uint_arg = va_arg(args, unsigned int);
					printed_chars += print_pointer(&uint_arg);
					break;

				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
