#include "main.h"

/**
 * is_printable - a function that evaluates whether a char is printable
 *
 * @c: is the char that will get evaluated
 *
 * Return: if c is printable return 1, otherwise return 0
*/

int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - is a function that appends ASSCI
 *	in a hexadecimal code to buffer
 *
 * @buffer: is an array of chars
 * @i: is an index at which to start appending
 * @ascii_code: the ASSCI code
 *
 * Return: always 3
*/

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char str[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code = ascii_code * -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = str[ascii_code / 16];
	buffer[i] = str[ascii_code % 16];

	return (3);
}

/**
 * is_digit - a function that Verifies if a char is a digit
 *
 * @c: is the char to be evaluated
 *
 * Return: if c is a digit return 1, otherwise return 0
*/

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - a function that casts a number to the specified size
 *
 * @num: is the number to be casted
 * @size: is a number that indicats the type to be casted
 *
 * Return: num casted value
*/

long int convert_size_number(long int num, int size)
{
	if (size == long_s)
	{
		return (num);
	}
	else if (size == short_s)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - a function that casts a number to the specified size
 *
 * @num: is the number to be casted
 * @size: is the number that indicats the type to be casted
 *
 * Return: the casted num value
*/

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == long_s)
	{
		return (num);
	}
	else if (size == short_s)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
