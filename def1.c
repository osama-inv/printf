#include "main.h"
/**
 * print_hexa - Outputs a hexadecimal number in lower or upper case.
 * @types: List of arguments for the format.
 * @map_to: Array of values to map the number to.
 * @buffer: Buffer array used for print handling.
 * @flags: Determines active formatting flags.
 * @flag_ch: Calculates active flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters successfully printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_len - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int num_init = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
{
buffer[i--] = '0';
}
buffer[BUFF_len - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & hash_f && num_init != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - Output an unsigned number.
 * @types: List of arguments for the format.
 * @buffer: Buffer array used for print handling.
 * @flags: Determine active formatting flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters successfully printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int i = BUFF_len - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
{
buffer[i--] = '0';
}
buffer[BUFF_len - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexa_upper - Outputs an unsigned number
 * in uppercase hexadecimal notation.
 * @types: List of arguments for the format.
 * @buffer: Buffer array used for print handling.
 * @flags: Determine active formatting flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters successfully printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexadecimal - Outputs an unsigned number in hexadecimal notation.
 * @types: List of arguments for the format.
 * @buffer: Buffer array used for print handling.
 * @flags: Determine active formatting flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters successfully printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_octal - Outputs an unsigned number in octal notation.
 * @types: List of arguments for the format.
 * @buffer: Buffer array used for print handling.
 * @flags: Determine active formatting flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters successfully printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int i = BUFF_len - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int num_init = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
{
buffer[i--] = '0';
}
buffer[BUFF_len - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & hash_f && num_init != 0)
{
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
