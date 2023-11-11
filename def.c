#include "main.h"

/**
 * print_binary - function that outputs an unsigned binary number
 * @types: is a list of the arguments
 * @buffer: is a buffer array for print handling
 * @flags: is used for calculating the active flags
 * @width: is the Width of the output
 * @precision: is the specification for precision
 * @size: is a specifier for the size
 * Return: the number of printed characters
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
/**
 * print_string - a function that displays a string
 * @types: is a list of the arguments
 * @buffer: is a buffer array for print handling
 * @flags: is used for calculating active flags
 * @width: is the width of the output
 * @precision: is the specification for precision
 * @size: is a size specifier
 * Return: the number of printed characters
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int longl = 0, i;
	char *strnn = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strnn == NULL)
	{
		strnn = "(null)";
		if (precision >= 6)
		{
			strnn = "      ";
		}
	}
	while (strnn[longl] != '\0')
		longl++;

	if (precision >= 0 && precision < longl)
		longl = precision;
	if (width > longl)
	{
		if (flags & minus_f)
		{
			write(1, &strnn[0], longl);
			for (i = width - longl; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - longl; i > 0; i--)
				write(1, " ", 1);
			write(1, &strnn[0], longl);
			return (width);
		}
	}
	return (write(1, strnn, longl));
}
/**
 * print_percent - a function that outputs a percent sign
 * @types: is a list of arguments
 * @buffer: is a buffer array for print handling
 * @flags: is used for calculating active flags
 * @width: is the width of the output
 * @precision: is the specification of precision
 * @size: is a specifier for the size
 * Return: the number of printed characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_char - a function that outputs a character
 * @types: is a list of arguments
 * @buffer: is an array used to manage printing
 * @flags: is used for calculating active flags
 * @width: is the width of the output
 * @precision: is the specification for precision
 * @size: is a specifier for the size
 * Return: is the number of printed characters
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision, size));
}
/**
 * print_int - a function that outputs an integer
 * @types: is a list of arguments
 * @buffer: is a buffer array for print handling
 * @flags:  is used to calculate active flags
 * @width: is the width of the output
 * @precision: is the specification for precision
 * @size: is a specifier for the size
 * Return: the number of printed characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_len - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_len - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}
