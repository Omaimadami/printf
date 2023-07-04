#include "main.h"

/**
 * print_number - Prints a number to stdout
 * @n: The number to be printed
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	_putchar('0' + n % 10);
	count++;

	return (count);
}

/**
 * print_unsigned_number - Prints an unsigned number to stdout
 * @n: The number to be printed
 *
 * Return: The number of characters printed
 */
int print_unsigned_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_number(n / 10);

	_putchar('0' + n % 10);
	count++;

	return (count);
}

/**
 * print_octal_number - Prints an octal number to stdout
 * @n: The number to be printed
 *
 * Return: The number of characters printed
 */
int print_octal_number(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal_number(n / 8);

	_putchar('0' + n % 8);
	count++;

	return (count);
}

/**
 * print_hex_number - Prints a hexadecimal number to stdout
 * @n: The number to be printed
 * @uppercase: Indicates whether to print uppercase or lowercase letters
 *
 * Return: The number of characters printed
 */
int print_hex_number(unsigned int n, int uppercase)
{
	int count = 0;
	char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
		count += print_hex_number(n / 16, uppercase);

	_putchar(hex_digits[n % 16]);
	count++;

	return (count);
}

/**
 * print_special_string - Prints a string with special characters to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_special_string(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
			{
				_putchar('0');
				count++;
			}
			count += 2 + print_hex_number((unsigned char)str[i], 1);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}

	return (count);
}

/**
 * print_pointer - Prints a pointer address
 * @ptr: The pointer to be printed
 *
 * Return: Number of characters printed
 */
int print_pointer(unsigned int *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int printed_chars = 0;

	printed_chars += _puts("0x");
	printed_chars += print_hex_number(address, 0);

	return (printed_chars);
}
